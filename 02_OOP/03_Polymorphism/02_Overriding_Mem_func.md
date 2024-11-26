# Overriding Member Functions

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

### **9. Default Arguments in Overriding**
- Default arguments are resolved based on the static type of the object, not the dynamic type.

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

---

### **Key Points to Remember**
1. **Virtual Keyword**: Use `virtual` in the base class to allow overriding.
2. **`override`**: Ensures correctness of overriding.
3. **`final`**: Prevents further overriding.
4. **Exact Match Required**: The function signature, including `const` qualifiers, must match.
5. **Access Specifiers**: Can change in the derived class but do not affect overriding functionality. 

