# Overview of Virtual Destructors in C++

A **virtual destructor** ensures proper cleanup of resources when an object is deleted through a pointer to a base class. Here's a summary of what you need to know:

---

### Key Takeaway:
- Use virtual destructors in base classes when you expect derived classes to manage additional resources and objects will be deleted through base class pointers.
- **Only needed in polymorphic base classes**: If a class is not intended to be used polymorphically, its destructor doesn't need to be virtual.
- **Virtual destructors are inherited**: If the base class destructor is virtual, all derived class destructors are implicitly virtual, even if not explicitly declared as such.
- When Virtual Destructors Are Not Needed:
   - **Non-Polymorphic Classes :** If a class is not used polymorphically (e.g., no virtual functions), it doesn't need a virtual destructor. 
   - **Final Classes :** If a class is marked as `final`, meaning it cannot be derived from, a virtual destructor is unnecessary because no polymorphic behavior is possible.
- Marking a function (including a destructor) as `virtual` in C++ creates or uses a **vtable** (virtual table) mechanism for the class. <u>**See below for documentation on vtable.**</u>

---

#### **1. What is a Virtual Destructor?**
- A destructor marked as `virtual` in the base class ensures that when a derived class object is deleted through a base class pointer, the **destructor of the derived class is called first**, followed by the base class destructor.
- Syntax:
  ```cpp
  class Base {
  public:
      virtual ~Base() {
          std::cout << "Base Destructor\n";
      }
  };

  class Derived : public Base {
  public:
      ~Derived() {
          std::cout << "Derived Destructor\n";
      }
  };
  ```


#### **2. Why Are They Important?**
- **Prevent resource leaks:** Without a virtual destructor, only the base class destructor would execute, leaving derived class resources unfreed.
- **Polymorphic behavior:** They are required for classes designed to be used polymorphically (e.g., with virtual functions or dynamic dispatch).



#### **3. Performance Impact**
- Slight overhead: Virtual destructors add a small cost due to the vtable lookup required for the destructor call.
- Acceptable for classes where proper cleanup is crucial.



#### **4. Rules and Best Practices**
- Always declare the destructor as virtual in base classes intended for polymorphism.
- If you use `delete` on a base pointer, ensure the base class has a virtual destructor.
- If you don't need polymorphism, avoid virtual destructors to save overhead.
- A pure virtual destructor (`= 0`) can be used to make a class abstract:
  ```cpp
  class Abstract {
  public:
      virtual ~Abstract() = 0;  // Pure virtual destructor
  };

  Abstract::~Abstract() {
      std::cout << "Abstract Destructor\n";
  }
  ```



#### **5. Example**

Without a virtual destructor:
```cpp
class Base {
public:
    ~Base() {
        std::cout << "Base Destructor\n";
    }
};

class Derived : public Base {
public:
    ~Derived() {
        std::cout << "Derived Destructor\n";
    }
};

Base* obj = new Derived();
delete obj;  // Only Base destructor is called (leaks Derived resources)
```

With a virtual destructor:
```cpp
class Base {
public:
    virtual ~Base() {
        std::cout << "Base Destructor\n";
    }
};

class Derived : public Base {
public:
    ~Derived() {
        std::cout << "Derived Destructor\n";
    }
};

Base* obj = new Derived();
delete obj;  // Both Derived and Base destructors are called
```


==================================================
---
## `Vtable`
==================================================
---


### **What is a Vtable?**
- A **vtable** (short for virtual table) is a per-class table maintained by the compiler to support **runtime polymorphism**.
- It stores pointers to the virtual functions of a class, allowing the correct function (or destructor) to be called at runtime, even when accessed through a base class pointer.

### **How Does the Vtable Work with Virtual Destructors?**

1. **Base Class with a Virtual Destructor**
   - When a class has a virtual destructor, the destructor is added to the vtable.
   - If a derived class overrides the destructor, the derived class’s destructor replaces the base class destructor’s pointer in the vtable.


2. **Deleting through a Base Pointer**
   - When you delete a derived class object through a base class pointer, the vtable ensures the **derived destructor is called first**, followed by the base destructor.
   - Example:
     ```cpp
     Base* obj = new Derived();
     delete obj;
     // Calls:
     // 1. Derived::~Derived()
     // 2. Base::~Base()
     ```

   Without a vtable (i.e., if the destructor is not virtual), only `Base::~Base` would be called, causing potential resource leaks in the derived class.

3. **Vtable Lookup**
   - At runtime, the vtable is consulted to determine the correct destructor to call based on the actual object type.
   - This lookup incurs a small overhead but enables polymorphic behavior.


### **When Does the Vtable Get Created?**
- The vtable is generated at **compile time**, but the vtable lookup occurs at **runtime**.
- Each class with virtual functions has its own vtable, and each polymorphic object has a hidden pointer (the **vptr**) pointing to its class’s vtable.


### **Performance Impact of the Vtable**
- **Small overhead**: A vtable lookup involves dereferencing a pointer to find the appropriate function.
- **Extra memory**: Each polymorphic object stores a `vptr`, which slightly increases the size of the object.
- The trade-off is usually acceptable given the flexibility and safety provided by runtime polymorphism.


### **Summary**
- Marking a destructor as `virtual` adds it to the vtable.
- The vtable ensures the correct destructor sequence (derived -> base) is invoked when deleting a derived object through a base pointer.
- This mechanism underpins all runtime polymorphism in C++ and is a key feature of object-oriented programming.

---

> **Do we still need virtual destructors when using `smart pointers` ?**

---
### **When Do You Still Need Virtual Destructors?**

1. **Polymorphic Base Classes**
   - If a base class is meant to be used polymorphically (e.g., you use `std::unique_ptr<Base>` to manage a `Derived` object), the base class needs a virtual destructor to ensure proper cleanup of derived class objects.

2. **Mixing Smart Pointers and Raw Pointers**
   - If part of the code still uses raw pointers or deletes objects polymorphically, a virtual destructor is essential. This may occur in legacy systems or performance-critical scenarios.

3. **Abstract Base Classes**
   - Classes designed as interfaces (pure virtual functions) usually need a virtual destructor, even in modern C++.
   
---