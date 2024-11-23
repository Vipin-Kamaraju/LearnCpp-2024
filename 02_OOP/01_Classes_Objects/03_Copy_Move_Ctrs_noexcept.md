=====================================================
---
# `Copy Constructor` vs `Copy Assignment Operator`
=====================================================
---

## Copy Constructor
```cpp
ClassName obj1;
ClassName obj2 = obj1;
```
1. **When is the copy constructor called?**
   - Whenever a new object is created from an existing object using:
     - Copy initialization (`ClassName obj2 = obj1;`)
     - Passing objects by value (`func(obj1);`)
     - Returning objects by value (`return obj1;`)

2. **Why is the copy constructor chosen?**
   - Because the operation involves **creating and initializing** a new object.

3. **Does this involve the copy assignment operator?**
   - No, because the copy assignment operator (`operator=`) is used only when assigning to an existing object.

4. **Default Behavior:**
   - If you don’t provide a copy constructor, the compiler generates a default one to perform member-wise copying.

## Copy Assignment Operator
1. **Copy Assignment Operator** is used **only when an object already exists** and you assign a value to it. For example:
   ```cpp
   ClassName obj1;
   ClassName obj2;
   obj2 = obj1; // Copy assignment operator is called
   ```

2. In the case of:
   ```cpp
   ClassName obj2 = obj1;
   ```
   `obj2` does **not already exist**. It is being created and initialized in one step. This triggers the **copy constructor**, not the assignment operator.
   


=====================================================
---
# `Move Constructor` vs `Move Assignment Operator`
=====================================================
---
The `move constructor` and `move assignement operator` are similar to the above explaination of how `copy constructor` and `copy assignment` operator work. The only difference in syntax is that in move the std::move() function is used.

## Syntax
1. **Move Constructor**
	```cpp
	ClassName(ClassName&& other) noexcept;
	```

	```cpp
	ClassName obj1;
	ClassName obj2 = std::move(obj1); // Move constructor is called
	```
    - `ClassName&&` is a **rvalue reference(&&)** to a temporary (moveable) object.
	- `noexcept` indicates whether a function can throw exceptions. 
2. **Move Assignment Operator**
   ```cpp
	ClassName& operator=(ClassName&& other) noexcept;
	```
   
   ```cpp
   ClassName obj1;
   ClassName obj2;
   obj2 = std::move(obj1); // Move assignment operator is called
   ```

## Lets dive into why we need them in the first place

A **move constructor** is a special function in C++ that allows you to "move" the data from one object to another instead of copying it. It's faster and more efficient because it **transfers ownership** of the data rather than duplicating it.

We cannot always copy data using references. In some cases we might actually need a copy of the original data and not the reference. Since if the original data is deleted it can lead to unintended behaviour. In this case we need the copy of the original data and not the reference. On the other hand if we use copy by value for large data this can lead to low performance. Hence we use std::move. This is also widely used by modern C++ which

- Avoid copying of unnecessary large resources
- Reallocate memory for containers like `std::vector` and `std::string`
- Reduces temporary copies, especially working with return values


### **Key Points:**
1. **What It Does**:
   - Transfers the resources (e.g., memory, files, data) from one object to another.
   - After the transfer, the original object is left in a safe but empty state.

2. **Why It's Needed**:
   - Copying large data (like arrays or strings) is slow because it duplicates everything.
   - Moving avoids this by reusing the original object's resources.

3. **How It Works**:
   - The move constructor uses **rvalue references** (`&&`), which indicate the source object is temporary and can be "moved."
   - Inside the move constructor, the original object’s resources (e.g., pointers) are reassigned to the new object, and the original object is reset.

4. **Other important points**
   - In case of `std::vector<int> var = somefunctionreturninglargevector()`, the **move constructor** is typically called, and this behavior is an **implicit optimization by the compiler** using modern C++ rules, specifically **Return Value Optimization (RVO)** and **move semantics**.
   
## Code Example
```cpp
#include <iostream>
#include <utility> // For std::move

class ClassName {
public:
    ClassName() { std::cout << "Default constructor\n"; }
    ClassName(const ClassName& other) { std::cout << "Copy constructor\n"; }
    ClassName(ClassName&& other) { std::cout << "Move constructor\n"; }
};

int main() {
    ClassName obj1;                 // Default constructor
    ClassName obj2 = obj1;          // Copy constructor
    ClassName obj3 = std::move(obj1); // Move constructor
    return 0;
}
```

**Output:**
```
Default constructor
Copy constructor
Move constructor
```

 - **Case 1 :**  `Move constructor` is defined `Copy Constructor` not defined
 	- `ClassName obj2 = obj1;` This will result in compiler error since default copy constructor will not be created by the compiler as the move constructor was defined.
 - **Case 2 :** `Move constructor` not defined `Copy Constructor` is defined
 	- `No Compiler Error` in this case for obj3 since the copy constructor will be used to create obj3.


### **Simple Example**:
Imagine you’re passing a box of books (resources) to a new person.

- **Copy Constructor**: You make a new box, duplicate all the books, and hand the copy to them. (Slow and uses more resources.)
- **Move Constructor**: You give them your box of books directly, and now you’re left with an empty box. (Fast and efficient!)

## **Move Constructor Analogy: Borrowing a Backpack**

Imagine you and your friend are going hiking. Your friend has a backpack filled with gear (resources).

#### **Copy Constructor**:
- If you use a copy constructor, you make an exact duplicate of your friend's backpack. This means you buy or collect the same gear, duplicate every single item, and create a new backpack.
- This takes time and effort because you must carefully copy everything your friend has.

#### **Move Constructor**:
- If you use a move constructor, your friend **hands over their backpack to you**. Now you have their backpack, and they no longer carry the gear (the old backpack becomes empty or light).
- It’s fast because you don’t have to duplicate anything—you just take ownership of what your friend already has.

#### Aftermath:
- In the move constructor case, your friend still has the empty or "safe" backpack (not in use, but functional), and you now carry all the resources.
---

=====================================================
---
# **`noexcept` Keyword**
=====================================================
---

The `noexcept` keyword is used in C++ to indicate whether a function **can throw exceptions**. It provides important information to the compiler and the programmer about the exception-safety guarantees of a function.
- When a function is marked as `noexcept` it tells the compiler that no exception will be thrown under any circumstances. It ensures safety and efficiency in standard containers.
- **Improves Performance :** The compiler can skip exception-handling mechanisms, improving speed and reducing binary size.
- **Standard Library Compatibility :** Many standard library functions (e.g., `std::move`, `std::vector::push_back`) rely on `noexcept` for correctness and performance. For instance, `std::vector` uses `noexcept` to determine whether an element can be safely moved during reallocation.
- **Compiler Optimizations :** The compiler avoids generating exception-handling code for functions marked as `noexcept`.
- Marking special member functions (like move constructors) with `noexcept` is common
- Destructors should generally be marked `noexcept` because exceptions thrown during stack unwinding can cause the program to terminate
- If the move constructor is not marked as `noexcept`, the container might fall back to a **costlier copy operation** because copying is considered safer when exceptions are possible.
