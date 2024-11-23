# DISABLING DEFAULT CONSTRUCTOR
---

Disabling the default constructor by explicitly marking it as `delete` serves several purposes in software design, particularly to enforce specific constraints or requirements in your code. Here are some common scenarios where this might be used:

---

### 1. **To Prevent Accidental Instantiation**
If the class is not meant to be instantiated directly, disabling the default constructor ensures that no default objects of the class can be created.

#### Example:
```cpp
class Utility {
public:
    Utility() = delete; // Prevent direct instantiation
    static int add(int a, int b) {
        return a + b;
    }
};
```
- **Use case:** Classes that act as utility classes or containers for only `static` methods or constants.

---

### 2. **To Enforce Parameterized Construction**
In some cases, you want objects of a class to always be initialized with specific parameters. Deleting the default constructor ensures that users cannot accidentally create an uninitialized object.

#### Example:
```cpp
class Config {
public:
    Config() = delete; // Prevent default construction
    Config(int setting) : setting_(setting) {}

private:
    int setting_;
};
```
- **Use case:** Enforcing mandatory initialization for proper object state.

---

### 3. **To Implement Singleton Pattern**
Singletons ensure that only one instance of a class exists. Deleting the default constructor prevents accidental instantiation.

#### Example:
```cpp
class Singleton {
public:
    static Singleton& getInstance() {
        static Singleton instance;
        return instance;
    }

private:
    Singleton() = default; // Can only be called internally
    Singleton(const Singleton&) = delete; // Prevents copying the `Singleton` object.
    void operator=(const Singleton&) = delete; // Prevents assignment to another `Singleton` object.
};
```
- **Use case:** Controlling the number of instances of a class.

---

### 4. **To Represent a Non-Instantiable Base Class**
Some classes are meant to serve as pure base classes (abstract interfaces) and should not be instantiated.

#### Example:
```cpp
class AbstractBase {
public:
    AbstractBase() = delete; // Prevent instantiation
    virtual void doSomething() = 0; // Pure virtual function
};
```
- **Use case:** Enforcing object-oriented design where derived classes must implement specific behavior.

---

### 5. **To Prevent Meaningless Objects**
If a default object doesn't have a meaningful state, it's better to disable its creation.

#### Example:
```cpp
class FileHandle {
public:
    FileHandle() = delete; // No default file handle
    FileHandle(const std::string& filePath) { /* Open file */ }
};
```
- **Use case:** Avoiding undefined or meaningless default states.

---

### 6. **To Support RAII Principles**
Resource Acquisition Is Initialization (RAII) requires that resources (like file handles or locks) are tied to object lifetimes. Deleting the default constructor ensures that the object always has a valid resource.

#### Example:
```cpp
class Lock {
public:
    Lock() = delete; // Lock must always be tied to a resource
    Lock(Mutex& mtx) : mutex_(mtx) { /* Acquire lock */ }
    ~Lock() { /* Release lock */ }

private:
    Mutex& mutex_;
};
```
- **Use case:** Preventing incomplete or meaningless RAII objects.

---

### 7. **To Enforce Design Patterns**
Some design patterns, such as factory patterns, require that objects be created through specific methods. Deleting the default constructor prevents deviations from this intended flow.

#### Example:
```cpp
class Product {
public:
    Product() = delete; // Use the factory method instead
    static Product createProduct(int type) { return Product(type); }

private:
    Product(int type) : type_(type) {}
    int type_;
};

int main(){
    Product p = Product::createProduct(1);
    return 0;
}
```
- In the above code, we want to create the object by only using the static function `createProduct`
- We can do this in the following way
- Disabling the default constructor 
- Also, the parameterized constructor is in Private --> meaning it is not accessible outside the class
- The parameterized constructor can only be called by the class
- We call the static function in main --> which calls the parameterized constructor in private
- We are doing this to ensure _type is always set during object creation
- Also, in the future if the `Product` creation changes in the future we only need to update the class in one location
- **Use case:** Restricting object creation to specific patterns.

#### Real world analogy
Think of the factory method as a "gatekeeper" for creating objects:

- Instead of directly entering a building (calling the constructor), you go through a reception desk (the factory method), which checks your purpose and lets you in (creates the object) only if appropriate.

---

### Summary:
Deleting the default constructor enforces discipline and avoids errors in the following cases:
1. When the class shouldn't be instantiated.
2. When meaningful initialization is mandatory.
3. To adhere to specific design patterns like Singleton or Factory.
4. To avoid meaningless or incomplete object states.
5. To implement abstract base classes or RAII-compliant classes.

By explicitly disabling the default constructor, you make the design intent of the class clear and reduce the risk of misuse.

================================================
---
## MORE ABOUT `Utility` CASE
================================================
---
Yes, that's correct! In the given code, the `Utility` class is designed to act as a **static utility class**, and disabling the default constructor ensures that it cannot be instantiated directly. Here's a breakdown of what this means:


### **Key Characteristics of the `Utility` Class**
1. **No Instantiation Allowed:**
   The line `Utility() = delete;` explicitly prevents the creation of any objects of this class. This ensures the class is used only as a collection of static functions.

   ```cpp
   Utility u; // Compilation error due to deleted constructor
   ```

2. **Static Functions Only:**
   All the functionality provided by the class is encapsulated in `static` functions. These functions can be accessed directly using the class name, without creating an instance.

   ```cpp
   int result = Utility::add(3, 5); // Correct usage
   ```

3. **No Non-Static Members:**
   Since there is no way to create an instance, the class is effectively stateless. It cannot hold member variables that depend on instantiation.

---

### **Common Use Cases for Such a Class**
1. **Utility or Helper Functions:**
   Classes like `Utility` are often used to group together a set of related helper functions. Examples include:
   - Mathematical utilities (`Math`, `Calculator`).
   - String manipulation utilities (`StringHelper`).
   - File handling utilities (`FileHelper`).

   ```cpp
   class Math {
   public:
       Math() = delete; // Prevent instantiation
       static int square(int x) {
           return x * x;
       }
   };
   ```

2. **Namespace-Like Behavior:**
   The `Utility` class acts somewhat like a namespace, providing a logical grouping for related functions. This is useful when you want to avoid cluttering the global namespace with free functions.

3. **Encapsulation of Static Behavior:**
   It ensures that users cannot mistakenly create objects that would imply some kind of stateful behavior.

---

### **Why This Design?**
- **Prevent Misuse:** By disabling the constructor, you make the intent of the class explicit, reducing the chance of errors.
- **Clarity:** It conveys that the class is purely for grouping functionality and not for representing an object with state or behavior.
- **Efficiency:** Since no instances are created, there’s no memory overhead associated with this class.

---

### **Inheritance Use Case**
While the `Utility` class could be inherited, this is usually rare because such utility classes are typically not designed for inheritance. If inheritance is intended, then disabling the constructor still makes sense for the base class.

Example:
```cpp
class AdvancedUtility : public Utility {
    // Additional static functions or utilities
};
```

However, in most cases, utility classes are not designed for inheritance but for static access.

---

### **Summary**
The `Utility` class in your example is ideal for grouping related static functions without allowing instantiation. This design is most commonly used for stateless, helper-type classes that do not represent objects but rather provide utility methods for other parts of the program.