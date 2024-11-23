In **Object-Oriented Programming (OOP)** using C++, a **class** is a blueprint for creating objects. It encapsulates data and methods that operate on that data. Here's an overview of class declarations in C++:

### 1. **Basic Syntax**
A class is declared using the `class` keyword, followed by the class name and a set of curly braces `{}`. The class body can contain:
- **Member variables (data members):** These hold the data attributes of the object.
- **Member functions (methods):** These define the behavior or operations on the data.

```cpp
class ClassName {
public:     // Access specifier
    int attribute;    // Data member
    void method() {   // Member function
        // method definition
    }
};
```

### 2. **Access Specifiers**
Access specifiers control the visibility of the class members:
- **`public`:** Members are accessible from outside the class.
- **`private`:** Members are accessible only within the class.
- **`protected`:** Members are accessible within the class and by derived classes.

```cpp
class Example {
private:
    int privateData; // Accessible only within the class

public:
    int publicData; // Accessible from outside the class

protected:
    int protectedData; // Accessible by derived classes
};
```

### 3. **Constructors and Destructors**
- **Constructor:** Special member function that initializes an object. It has the same name as the class and no return type.
- **Destructor:** Special member function to clean up when an object is destroyed. It starts with a tilde `~` and has no return type.

```cpp
class MyClass {
public:
    MyClass() { // Constructor
        // Initialization code
    }

    ~MyClass() { // Destructor
        // Cleanup code
    }
};
```

### 4. **Defining Methods Outside the Class**
Methods can be defined outside the class using the scope resolution operator `::`.

```cpp
class MyClass {
public:
    void sayHello(); // Method declaration
};

void MyClass::sayHello() { // Method definition
    std::cout << "Hello!" << std::endl;
}
```

### 5. **Creating Objects**
Objects are instances of a class, created like this:

```cpp
MyClass obj; // Creates an object of MyClass
obj.sayHello(); // Access public method
```

### 6. **Encapsulation, Inheritance, and Polymorphism**
- **Encapsulation:** Bundling of data and methods within a class.
- **Inheritance:** A class can derive from another class, inheriting its members.
- **Polymorphism:** Objects of derived classes can be treated as objects of the base class, supporting dynamic behavior.

Example:

```cpp
class Base {
public:
    void baseMethod() {
        std::cout << "Base class method" << std::endl;
    }
};

class Derived : public Base {
public:
    void derivedMethod() {
        std::cout << "Derived class method" << std::endl;
    }
};
```

### 7. **Advanced Features**
- **Friend Functions:** Functions that can access private and protected members of a class.
- **Static Members:** Members shared by all objects of a class.
- **Overloading:** Defining multiple constructors or operators with different parameters.

Classes in C++ form the foundation of OOP, allowing structured, modular, and reusable code.