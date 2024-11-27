# Overriding Member Functions

---

## **Key Points to Remember**
1. **Virtual Keyword**: Use `virtual` in the base class to allow overriding.
2. **`override`**: Ensures correctness of overriding.
3. **`final`**: Prevents further overriding.
4. **Exact Match Required**: The function signature, including `const` qualifiers, must match.
5. **Access Specifiers**: Can change in the derived class but do not affect overriding functionality. 

---

## **1. Standard Function Overriding Using `override` Keyword**
- Starting from C++11, the `override` keyword explicitly indicates that a function is meant to override a base class function.
- If there is a mismatch (e.g., incorrect signature), the compiler generates an error.

#### Example:
```cpp
class Base {
public:
    virtual void func(int x) {}
};

class Derived : public Base {
public:
    void func(int x) override {} // Correct
    // void func(double x) override {} // Compiler error: No function to override
};
```

---

## **2. Using `final` Keyword**
- A function declared with the `final` specifier cannot be overridden in any further derived class.

#### Example:
```cpp
class Base {
public:
    virtual void func() {}
};

class Derived : public Base {
public:
    void func() final {} // No further overriding allowed
};

class FurtherDerived : public Derived {
public:
    // void func() override {} // Compiler error: func() is final
};
```
- In the above code `final` keyword does 2 things:
	- It allows override the `func()` in Derived Class
    - It does not allow override in the futher derived classes


---

## **4. Covariant Return Types**
- Overriding allows derived classes to change the return type of a function to a derived type of the base class's return type.
- This works only if the base function is virtual.

#### Example:
```cpp
class Base {
public:
    virtual Base* clone() {
        return new Base(*this); // Creating a copy of calling object of type Base
    }
};

class Derived : public Base {
public:
    Derived* clone() override { // Covariant return type
        return new Derived(*this); // Creating a copy of calling object of type Derived
    }
};

int main() {
    Base* b = new Derived(); // A Derived object, but pointer is of type Base*
    Base* b_copy = b->clone(); // Calls Derived::clone()
    
    // Without covariant return types, the returned type would still be Base*, requiring a cast.
    delete b;
    delete b_copy;
    return 0;
}
```

**Explaination**

- This code is using the **Prototype Design Pattern**
- It is used to create copy of objects without using type casting (which is error prone)
- In the above code `return new Base(*this);` is creating a copy of the Base object it is called on.
- This function is overloaded with the `return new Derived(*this);` which then returns a created a new copy of the Derived Class object

### **Use Cases of Covariant Return Types**

1. **Polymorphic Object Cloning**
   - `clone()` is a common design pattern used in frameworks requiring polymorphic behavior (e.g., **Prototype Design Pattern**).
   - It ensures that derived class objects are correctly duplicated without requiring explicit type casts.

2. **Avoiding Type Casting**
   - Without covariant return types, the return type would always be `Base*`, and users would need to manually cast the result back to `Derived*`, which is error-prone.

3. **Object Factories**
   - Covariant return types simplify the implementation of object factories where different types of objects need to be created dynamically.

4. **Ensuring Type Safety**
   - Covariant return types help to maintain type safety in object-oriented hierarchies while still leveraging polymorphism.

### **Benefits**

- **Type Safety**: Avoids unsafe casts.
- **Clarity**: Makes the API easier to use since the correct type is returned directly.
- **Extensibility**: Allows derived classes to specialize return types while retaining compatibility with base class interfaces.


---

### **5. Const-Correctness in Overriding**
- A derived class can only override a base class function if the `const` qualifier matches.

#### Example:
```cpp
class Base {
public:
    virtual void func() const {}
};

class Derived : public Base {
public:
    void func() const override {} // Correct
    // void func() override {} // Compiler error: Missing const qualifier
};
```

---

### **6. Pure Virtual Function Overriding**

---

### **7. Access Specifier in Overriding**
- The access specifier of the overridden function in the derived class can be different from the base class.
- **When a function in a base class is overridden in a derived class, the derived class can change the access specifier of the overridden function.**
- The access specifier in the derived class determines how the function is accessed via an object of the derived class. This behavior is distinct from the base class's access specifier.
- So in the below code the `func()` is made public eventhoough it is protected in BaseClass.
- You can make a `protected` or `private` base class member `public` in the derived class.
- However, you cannot make a `public` base class member more restrictive (e.g., `protected` or `private`) in the derived class.

#### Example:
```cpp
class Base {
protected:
    virtual void func() {}
};

class Derived : public Base {
public:
    void func() override {} // Changed access to public
};
```

---

### **8. Default Arguments in Overriding**
> **Default arguments are resolved based on the static type of the object, not the dynamic type**
- This means that the deafult value is determined at compile time and not runtime
- Read further explanation of this code below and what the default values will be
- **Case 1 Static Type:** when obj is created with `Derived obj;` **x=20** since at compile time compiler calls the `Derived::func()`
- **Case 2 Dynamic Type:** when obj is created with `Base* ptr= new Derived();` eventhough `ptr` is pointing to `Derived` class. The compiler does not know this at compile time so it assigns the default value of x from Base Class **x=10;**
- **Case 3 Static Type:** Default value can be directly assigned by `Derived obj(30)` in this case x=30; which is evaluated at compile time.

#### Example:
```cpp
class Base {
public:
    virtual void func(int x = 10) {
        cout << "Base: " << x << endl;
    }
};

class Derived : public Base {
public:
    void func(int x = 20) override {
        cout << "Derived: " << x << endl;
    }
};

int main() {
    Base* obj = new Derived();
    obj->func(); // Output: Base: 10
    return 0;
}
```

### Explanation:

1. **Static Type vs. Dynamic Type**:
   - **Static Type**:
     - The type of the variable as declared in the code.
     - This is determined at **compile time**.
   - **Dynamic Type**:
     - The actual type of the object that the variable refers to at runtime.
     - This is determined at **runtime**, especially in cases of polymorphism.

2. **Default Arguments**:
   - Default arguments in C++ are specified at the **function declaration** or **definition**.
   - They are substituted by the compiler **at the call site** during **compile time**.

3. **Virtual Functions**:
   - When calling a virtual function, the **dynamic type** of the object determines which function implementation is executed at runtime (dynamic dispatch).
   - However, the **default arguments** are resolved at compile time based on the **static type** of the pointer or reference used to make the call.

### What Happens?

1. **Default Argument Resolution**:
   - At the call site `obj->func();`, the compiler substitutes the **default argument value**.
   - The compiler uses the **static type** of `obj`, which is `Base*`.
   - Hence, the default argument `x = 10` (from the `Base` class) is used.

2. **Function Execution**:
   - Since `func` is a **virtual function**, the **dynamic type** of `obj` (which is `Derived`) determines which function implementation is executed at runtime.
   - Therefore, `Derived::func` is executed.

3. **Output**:
   - The actual function called is `Derived::func`, but it uses the default argument `x = 10` from the `Base` class.
   - Output:
     ```
     Derived func, x = 10
     ```

### Why Does This Happen?

- **Compile-Time Argument Resolution**:
   - Default arguments are substituted at the **call site** during compile time.
   - At this point, the compiler only knows the **static type** of the object or pointer.

- **Run-Time Function Resolution**:
   - Virtual function dispatch happens at runtime based on the **dynamic type** of the object.
   - The function implementation executed corresponds to the object's dynamic type, but the default argument value used comes from the static type.


### Key Takeaways:

1. Default arguments are bound to the **static type** of the variable or pointer at the call site.
2. Virtual functions are resolved dynamically based on the **dynamic type** of the object at runtime.
3. This can lead to scenarios where the default argument comes from the base class, but the derived class's function implementation is executed.


### How to Avoid Confusion?

If you want to ensure the correct default arguments are used for the derived class:
- **Avoid specifying default arguments in both the base and derived classes.**
- Alternatively, use explicit arguments when calling the function:

```cpp
obj->func(20); // Explicitly specify the argument to avoid default argument confusion
```

This ensures that both the function and the argument align with your expectations.

###

---



