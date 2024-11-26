# Types of Polymorphism in C++: Static vs. Dynamic

| **Type of Polymorphism**        | **Classification**    | **Description**                                                                 |
|----------------------------------|-----------------------|---------------------------------------------------------------------------------|
| **Function Overloading**         | Static                | Multiple functions with the same name but different parameter lists.           |
| **Operator Overloading**         | Static                | Redefining operators to work with user-defined types.                          |
| **Template Instantiation**       | Static                | Code generated at compile time for specific data types.                        |
| **Virtual Functions**            | Dynamic               | Function resolution happens at runtime using a base class pointer/reference.   |
| **Runtime Type Identification**  | Dynamic               | Determining the type of an object at runtime using `typeid` or `dynamic_cast`. |


- **Static Polymorphism**: Resolved at **compile time** (e.g., function overloading, operator overloading, templates).
- **Dynamic Polymorphism**: Resolved at **runtime** (e.g., virtual functions, runtime type identification).

---
## **Questions**

### 1. **What is the difference between static and dynamic polymorphism in C++?**
   - **Static polymorphism** is resolved at compile time using techniques like **function overloading**, **operator overloading**, and **templates**.
   - **Dynamic polymorphism**, on the other hand, is resolved at runtime using **virtual functions** and the **vtable** mechanism.
   - Key differences were summarized in a comparison table.

---

### 2. **If I create an object of `Circle` as `Circle c;` and call `c.draw();`, will this be resolved at runtime or compile time?**
   - **Code Snippet:**
     ```cpp
     Circle c;
     c.draw(); // Calls Circle::draw() at compile time.
     ```
   - Answer: This is resolved at **compile time**, as the compiler knows the exact type (`Circle`) of the object at compile time. There’s no need for runtime dispatch.

---

### 3. **Why do we use base class pointers (`Shape*`) when we know the class type?**
   - Using base class pointers enables **runtime polymorphism**, allowing a single interface (`Shape*`) to manage multiple derived types (`Circle`, `Square`, etc.).
   - Benefits include:
     - Writing **generic code**.
     - Achieving **extensibility** without modifying existing code.
     - Handling **dynamic behavior** at runtime.

---

### 4. **Is an abstract class considered runtime or compile-time polymorphism?**
   - Answer: Abstract classes primarily facilitate **runtime polymorphism** when methods are invoked through a **base class pointer or reference**.
   - **Compile-time resolution** occurs only when calling methods directly on derived class objects.

Here’s a complete code snippet demonstrating **runtime polymorphism** using an abstract class, **without using `new` and `delete`**, by leveraging **smart pointers**.

#### Code Example

```cpp
#include <iostream>
#include <vector>
#include <memory>

// Abstract Base Class
class Shape {
public:
    virtual void draw() const = 0; // Pure virtual function
    virtual ~Shape() {}           // Virtual destructor
};

// Derived Class: Circle
class Circle : public Shape {
public:
    void draw() const override {
        std::cout << "Drawing Circle" << std::endl;
    }
};

// Derived Class: Square
class Square : public Shape {
public:
    void draw() const override {
        std::cout << "Drawing Square" << std::endl;
    }
};

int main() {
    // Using a vector of smart pointers to manage Shape objects
    std::vector<std::unique_ptr<Shape>> shapes;

    // Adding different shapes to the collection
    shapes.push_back(std::make_unique<Circle>()); // Add a Circle
    shapes.push_back(std::make_unique<Square>()); // Add a Square

    // Calling the draw method on each shape (runtime polymorphism)
    for (const auto& shape : shapes) {
        shape->draw(); // Calls the correct draw() method based on the object type
    }

    // No need for delete: smart pointers automatically clean up memory
    return 0;
}
```

---

### 5. **Is `new` and `delete` still used for creating classes in modern C++? Are there alternatives?**
   - We discussed that modern C++ discourages the use of `new` and `delete` in favor of **smart pointers** (`std::unique_ptr`, `std::shared_ptr`) and **automatic storage** (stack-allocated objects).
   - Smart pointers automatically manage memory, reduce the risk of leaks, and simplify code.
   - Avoid using `new()` and `delete()` as shown below
   ```cpp
int main() {
    Shape* shape1 = new Circle();
    Shape* shape2 = new Rectangle();

    shape1->draw(); // Calls Circle::draw() at runtime
    shape2->draw(); // Calls Rectangle::draw() at runtime

    delete shape1;
    delete shape2;
    return 0;
}
```
   


---

### 6. **How can I use templates to create shapes (`Circle`, `Square`) in the same container?**
   - We provided a **template-based solution** to add shapes to a container using smart pointers:
     - A `std::vector<std::unique_ptr<Shape>>` was used to store polymorphic objects.
     - A **template function** added derived objects (`Circle`, `Square`) to the container dynamically.
   - **Code Snippet:**
     ```cpp
     template <typename T, typename... Args>
     void addShape(std::vector<std::unique_ptr<Shape>>& shapes, Args&&... args) {
         shapes.push_back(std::make_unique<T>(std::forward<Args>(args)...));
     }
     ```

---

### 7. **Can the `addShape` function be part of the `Shape` class?**
   - We modified the solution to integrate the shape creation logic into the `Shape` class as a static template function.
   - **Code Snippet:**
```cpp
#include <iostream>
#include <vector>
#include <memory>

// Base class
class Shape {
public:
    virtual void draw() const = 0; // Pure virtual function
    virtual ~Shape() {}

    // Static method to add shapes to the container
    template <typename T, typename... Args>
    static void addShape(std::vector<std::unique_ptr<Shape>>& shapes, Args&&... args) {
        shapes.push_back(std::make_unique<T>(std::forward<Args>(args)...));
    }
};

// Derived class Circle
class Circle : public Shape {
public:
    void draw() const override {
        std::cout << "Drawing Circle" << std::endl;
    }
};

// Derived class Square
class Square : public Shape {
public:
    void draw() const override {
        std::cout << "Drawing Square" << std::endl;
    }
};

int main() {
    // Container to hold different shapes
    std::vector<std::unique_ptr<Shape>> shapes;

    // Add shapes using the static method in Shape
    Shape::addShape<Circle>(shapes); // Add a Circle
    Shape::addShape<Square>(shapes); // Add a Square

    // Draw all shapes
    for (const auto& shape : shapes) {
        shape->draw(); // Calls the appropriate draw function
    }

    return 0;
}
```

---

### **Key Code Snippets and Classification**

| **Code Snippet**                               | **Compile Time or Runtime?**      | **Explanation**                                       |
|------------------------------------------------|------------------------------------|-------------------------------------------------------|
| `Circle c; c.draw();`                          | Compile Time                      | Object type is known, resolved by compiler.           |
| `Shape* shape = new Circle(); shape->draw();`  | Runtime                           | Virtual function, resolved via vtable at runtime.     |
| **Template Function for Adding Shapes**        | Compile Time                      | Templates generate code specific to the type.         |
| **Using Smart Pointers with Virtual Functions**| Runtime (for `draw()` call)       | Memory management is automatic, but virtual call.     |

---

### **Final Takeaways**

1. **Polymorphism**:
   - Use **static polymorphism** (e.g., templates) for compile-time efficiency and **dynamic polymorphism** (e.g., virtual functions) for runtime flexibility.
2. **Modern C++ Memory Management**:
   - Prefer **smart pointers** over `new` and `delete` for safety and readability.
3. **Templates and Extensibility**:
   - Templates combined with polymorphism allow flexible and type-safe designs for collections and shape management.
4. **Code Integration**:
   - Centralizing logic (e.g., `addShape` in the `Shape` class) can improve encapsulation but should balance against single-responsibility principles. 

