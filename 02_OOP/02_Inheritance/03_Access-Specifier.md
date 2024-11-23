Great! Let's move to the next topic: **Access Specifiers in Inheritance**.

### Access Specifiers in Inheritance

Access specifiers (`public`, `protected`, `private`) determine how the members of a base class are inherited in a derived class and how they can be accessed.

#### Member Accessibility in Derived Classes
The following table shows how access specifiers of the base class affect member visibility in the derived class:

| Base Class Member Type | Public Inheritance | Protected Inheritance | Private Inheritance |
|------------------------|---------------------|------------------------|----------------------|
| **Public Members**     | Public             | Protected              | Private              |
| **Protected Members**  | Protected          | Protected              | Private              |
| **Private Members**    | Not Accessible     | Not Accessible         | Not Accessible       |

#### Details of Access Specifiers:
1. **Public Inheritance**:
   - Public members of the base class remain public in the derived class.
   - Protected members of the base class remain protected in the derived class.
   - Example:
     ```cpp
     class Base {
     public:
         int publicVar;
     protected:
         int protectedVar;
     private:
         int privateVar;
     };

     class Derived : public Base {
         void show() {
             publicVar = 10;     // Accessible
             protectedVar = 20; // Accessible
             // privateVar = 30; // Not Accessible
         }
     };
     ```

2. **Protected Inheritance**:
   - Public and protected members of the base class become protected in the derived class.
   - Example:
     ```cpp
     class Derived : protected Base {
         void show() {
             publicVar = 10;     // Accessible but becomes protected
             protectedVar = 20; // Accessible
         }
     };
     ```

3. **Private Inheritance**:
   - Public and protected members of the base class become private in the derived class.
   - Example:
     ```cpp
     class Derived : private Base {
         void show() {
             publicVar = 10;     // Accessible but becomes private
             protectedVar = 20; // Accessible but becomes private
         }
     };
     ```

4. **Private Members**:
   - Private members of the base class are never directly accessible in the derived class, regardless of the type of inheritance.

---
## What is a protected member variable and Use cases

### Protected Member Variable in C++

A **protected member variable** in a class is accessible:

1. **Within the same class** where it is declared.
2. **In derived classes** (regardless of the type of inheritance used).

It is **not accessible** outside the class hierarchy (i.e., not accessible by objects of the class).

#### Syntax Example:
```cpp
class Base {
protected:
    int protectedVar;
};

class Derived : public Base {
public:
    void setProtectedVar(int value) {
        protectedVar = value; // Accessible within the derived class
    }
};

int main() {
    Base obj;
    // obj.protectedVar = 10; // Error: Protected member not accessible from outside
    return 0;
}
```

### Use Case of Protected Members

Protected members are useful when you want to allow **derived classes** to access and manipulate certain members of the base class, but you do not want to expose them to the outside world.

#### Common Use Cases:
1. **Encapsulation with Extension**:
   - Allows derived classes to build upon base class functionality without exposing sensitive data or implementation details to the outside world.
   - Example: A `Shape` class with a `protected area` variable, so specific shapes like `Circle` or `Rectangle` can compute and use it internally.

2. **Intermediate Data Sharing**:
   - When intermediate computation values or helper data are needed across a hierarchy of classes.
   - Example: A `Vehicle` class with a `protected maxSpeed` variable, allowing derived classes like `Car` and `Bike` to modify or use it for their specific behavior.

3. **Prevent Overexposure**:
   - Protects data from being directly accessed or modified by external code, maintaining encapsulation while supporting inheritance.

Would you like to see more examples or explore scenarios where protected members fit into a design?

---