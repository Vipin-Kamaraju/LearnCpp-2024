# Different ways to achieve Polymorphism in C++
---

### **1. Using Virtual Functions in Inheritance**
   - Virtual functions in a base class allow derived classes to override the behavior of methods. This is the most common form of runtime polymorphism in object-oriented programming.

   Example:
   ```cpp
   class Animal {
   public:
       virtual void speak() = 0; // Pure virtual function
   };

   class Dog : public Animal {
   public:
       void speak() override {
           std::cout << "Woof!" << std::endl;
       }
   };

   class Cat : public Animal {
   public:
       void speak() override {
           std::cout << "Meow!" << std::endl;
       }
   };

   void makeAnimalSpeak(Animal* animal) {
       animal->speak(); // Calls the appropriate derived class method
   }
   ```

---

### **2. Using Abstract Classes**
   - In C++, pure abstract classes (classes with only pure virtual functions) can enforce that derived classes implement specific methods. These are also called interfaces.

   Example:
   ```cpp
   class Shape {
   public:
       virtual void draw() = 0; // Pure virtual function
   };

   class Circle : public Shape {
   public:
       void draw() override {
           std::cout << "Drawing Circle" << std::endl;
       }
   };

   class Square : public Shape {
   public:
       void draw() override {
           std::cout << "Drawing Square" << std::endl;
       }
   };
   ```

---

### **3. Function Overloading (Compile-Time Polymorphism)**
   - Compile-time polymorphism is achieved by defining multiple functions with the same name but different signatures in the same scope.

   Example:
   ```cpp
   class Math {
   public:
       int add(int a, int b) {
           return a + b;
       }

       double add(double a, double b) {
           return a + b;
       }
   };
   ```

---

### **4. Operator Overloading**
   - Similar to function overloading, operator overloading allows you to redefine the behavior of operators for user-defined types.

   Example:
   ```cpp
   class Vector {
   public:
       int x, y;
       Vector(int x, int y) : x(x), y(y) {}
       Vector operator+(const Vector& v) {
           return Vector(x + v.x, y + v.y);
       }
   };
   ```

---

### **5. Method Overriding**
   - This is a key mechanism of polymorphism, allowing derived classes to provide their specific implementation of a base class method.

   Example:
   ```cpp
   class Base {
   public:
       virtual void show() {
           std::cout << "Base class" << std::endl;
       }
   };

   class Derived : public Base {
   public:
       void show() override {
           std::cout << "Derived class" << std::endl;
       }
   };
   ```

---

### **6. Templates and Generic Programming**
   - Templates in C++ allow polymorphism by enabling functions and classes to work with any data type.

   Example:
   ```cpp
   template <typename T>
   T add(T a, T b) {
       return a + b;
   }
   ```

---

### **7. Composition and Delegation**
   - Instead of relying on inheritance, you can use composition to achieve polymorphism by delegating behavior to member objects.

   Example:
   ```cpp
   class Engine {
   public:
       void start() {
           std::cout << "Engine starting..." << std::endl;
       }
   };

   class Car {
   private:
       Engine engine; // Composition
   public:
       void start() {
           engine.start(); // Delegation
       }
   };
   ```

---

### **8. Typecasting and Dynamic Binding**
   - You can achieve polymorphism by casting objects to a base class and then using dynamic binding to determine the method to call.

   Example:
   ```cpp
   void display(Animal* animal) {
       if (Dog* dog = dynamic_cast<Dog*>(animal)) {
           dog->speak();
       } else if (Cat* cat = dynamic_cast<Cat*>(animal)) {
           cat->speak();
       }
   }
   ```

---

### **9. Lambda Functions**
   - In modern C++, polymorphism can be achieved using lambda expressions, which encapsulate behavior in small, callable objects.

   Example:
   ```cpp
   std::function<void()> sayHello = []() {
       std::cout << "Hello!" << std::endl;
   };
   sayHello();
   ```

---

### **10. std::variant and std::visit** (Since C++17)
   - `std::variant` enables polymorphism by acting as a type-safe union, and `std::visit` can be used to operate on the currently active type.

   Example:
   ```cpp
   #include <variant>
   #include <iostream>

   void printVariant(const std::variant<int, double, std::string>& v) {
       std::visit([](auto&& arg) {
           std::cout << arg << std::endl;
       }, v);
   }

   int main() {
       std::variant<int, double, std::string> value = 42;
       printVariant(value); // Prints: 42
       value = "Hello";
       printVariant(value); // Prints: Hello
   }
   ```

---

Each method focuses on different forms of polymorphism in C++, including **compile-time** (templates, function/operator overloading) and **runtime** (virtual functions, dynamic binding) approaches. Modern features like lambdas and `std::variant` provide additional ways to achieve polymorphic behavior.