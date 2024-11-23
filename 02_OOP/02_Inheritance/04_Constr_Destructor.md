### Constructors and Destructors in Inheritance

In inheritance, constructors and destructors of the base and derived classes play a vital role in initializing and cleaning up objects.

#### Key Points:
1. **Base Class Constructor**:
   - A base class constructor is always called **before** the derived class constructor.
   - If no explicit constructor call is made, the **default constructor** of the base class is automatically invoked.

2. **Derived Class Constructor**:
   - The derived class constructor is executed **after** the base class constructor completes.

3. **Base Class Destructor**:
   - The base class destructor is called **after** the derived class destructor.

4. **Order of Calls**:
   - Constructor calls: **Base → Derived**
   - Destructor calls: **Derived → Base**

5. **Explicit Constructor Invocation**:
   - You can explicitly invoke a specific base class constructor from the derived class constructor using an **initializer list**.

#### Example:
```cpp
#include <iostream>
using namespace std;

class Base {
public:
    Base() {
        cout << "Base Constructor Called" << endl;
    }
    ~Base() {
        cout << "Base Destructor Called" << endl;
    }
};

class Derived : public Base {
public:
    Derived() {
        cout << "Derived Constructor Called" << endl;
    }
    ~Derived() {
        cout << "Derived Destructor Called" << endl;
    }
};

int main() {
    Derived obj; // Creating object of derived class
    return 0;
}
```

#### Output:
```
Base Constructor Called
Derived Constructor Called
Derived Destructor Called
Base Destructor Called
```

#### Custom Initialization in Derived Class:
```cpp
class Base {
    int value;
public:
    Base(int x) : value(x) {
        cout << "Base Constructor with value: " << value << endl;
    }
};

class Derived : public Base {
public:
    Derived(int x) : Base(x) { // Explicitly invoking Base constructor
        cout << "Derived Constructor" << endl;
    }
};
```

#### Key Takeaways:
- Constructors initialize objects in a **top-down** approach.
- Destructors clean up objects in a **bottom-up** approach.
- Always use initializer lists to initialize base class members or parameters.

