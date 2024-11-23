Here is a brief explanation of each type of inheritance in C++:

1. **Single Inheritance**:
   - A derived class inherits from a single base class.
   - Example:
     ```cpp
     class Base {
         // Base class code
     };

     class Derived : public Base {
         // Derived class code
     };
     ```

2. **Multiple Inheritance**:
   - A derived class inherits from more than one base class.
   - Example:
     ```cpp
     class Base1 {
         // Base1 code
     };

     class Base2 {
         // Base2 code
     };

     class Derived : public Base1, public Base2 {
         // Derived class code
     };
     ```

3. **Multilevel Inheritance**:
   - A class is derived from a class that is already derived from another class (a chain of inheritance).
   - Example:
     ```cpp
     class Base {
         // Base class code
     };

     class Intermediate : public Base {
         // Intermediate class code
     };

     class Derived : public Intermediate {
         // Derived class code
     };
     ```

4. **Hierarchical Inheritance**:
   - Multiple derived classes inherit from a single base class.
   - Example:
     ```cpp
     class Base {
         // Base class code
     };

     class Derived1 : public Base {
         // Derived1 class code
     };

     class Derived2 : public Base {
         // Derived2 class code
     };
     ```

5. **Hybrid (or Virtual) Inheritance**:
   - A combination of two or more types of inheritance. It often involves multiple inheritance and is used to resolve issues like the **diamond problem** by using **virtual inheritance**.
   - Example:
     ```cpp
     class Base {
         // Base class code
     };

     class Derived1 : virtual public Base {
         // Derived1 class code
     };

     class Derived2 : virtual public Base {
         // Derived2 class code
     };

     class FinalDerived : public Derived1, public Derived2 {
         // FinalDerived class code
     };
     ```

