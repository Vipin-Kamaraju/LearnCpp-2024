### C++ Templates: Q&A for Quick Revision

---

### **Basic Templates**
1. **Q**: What is the purpose of templates in C++?  
   **A**: Templates enable generic programming, allowing you to write type-agnostic and reusable code for different data types.

2. **Q**: Write a simple function template for adding two numbers.  
   **A**:
   ```cpp
   template <typename T>
   T add(T a, T b) {
       return a + b;
   }
   ```

3. **Q**: What is the syntax for a class template?  
   **A**:
   ```cpp
   template <typename T>
   class Example {
       T value;
   public:
       Example(T val) : value(val) {}
   };
   ```

4. **Q**: Can a class template have multiple parameters?  
   **A**: Yes, like:
   ```cpp
   template <typename T1, typename T2>
   class Example {
       T1 a;
       T2 b;
   };
   ```

---

### **Template Specialization**
5. **Q**: What is full specialization?  
   **A**: Providing a specific implementation of a template for a particular type.
   ```cpp
   template <>
   class Printer<int> {
       void print(int value) { cout << "Integer: " << value << endl; }
   };
   ```

6. **Q**: What is partial specialization?  
   **A**: Specializing only part of a template’s parameters.
   ```cpp
   template <typename T>
   class Example<T, int> { /* Specialized behavior for T and int */ };
   ```

7. **Q**: When should you use specialization?  
   **A**: When you need a different implementation for a specific type or a subset of types.

---

### **Variadic Templates**
8. **Q**: What are variadic templates?  
   **A**: Templates that accept a variable number of arguments using `...`.

9. **Q**: Write a variadic template function that prints all arguments.  
   **A**:
   ```cpp
   template <typename T, typename... Args>
   void print(T first, Args... rest) {
       cout << first << " ";
       print(rest...);
   }
   ```

10. **Q**: What are fold expressions?  
    **A**: Fold expressions simplify operations on parameter packs. Example:
    ```cpp
    template <typename... Args>
    auto sum(Args... args) {
        return (args + ...); // Sums all arguments
    }
    ```

---

### **Template Metaprogramming**
11. **Q**: What is template metaprogramming (TMP)?  
    **A**: Using templates to perform computations at compile time.

12. **Q**: Write a TMP example to compute factorials.  
    **A**:
    ```cpp
    template <int N>
    class Factorial {
    public:
        static constexpr int value = N * Factorial<N - 1>::value;
    };

    template <>
    class Factorial<0> {
    public:
        static constexpr int value = 1;
    };
    ```

13. **Q**: How does TMP recursion terminate?  
    **A**: By defining a **base case specialization**, like:
    ```cpp
    template <>
    class Factorial<0> {
        static constexpr int value = 1;
    };
    ```

---

### **Type Traits and `std::enable_if`**
14. **Q**: What is `std::enable_if`?  
    **A**: A type trait that conditionally enables/disables templates based on compile-time conditions.

15. **Q**: Write a function that works only for integral types.  
    **A**:
    ```cpp
    template <typename T>
    typename std::enable_if<std::is_integral<T>::value, void>::type
    printIfIntegral(T value) {
        cout << value << " is integral" << endl;
    }
    ```

16. **Q**: What is `std::is_integral`?  
    **A**: A type trait that checks if a type is integral (`int`, `char`, etc.).

---

### **Curiously Recurring Template Pattern (CRTP)**
17. **Q**: What is CRTP?  
    **A**: A technique where a class inherits from a template instantiation of itself:
    ```cpp
    template <typename Derived>
    class Base {
        void interface() {
            static_cast<Derived*>(this)->implementation();
        }
    };
    ```

18. **Q**: What are the benefits of CRTP?  
    **A**:
    - Enables static polymorphism.
    - Avoids the overhead of virtual functions.
    - Provides reusable functionality to derived classes.

---

### **Fold Expressions**
19. **Q**: What is the syntax for a fold expression?  
    **A**:
    ```cpp
    (pack + ...) // Unary fold
    (pack1 + ... + packN) // Binary fold
    ```

20. **Q**: Write a function using fold expressions to calculate the product of arguments.  
    **A**:
    ```cpp
    template <typename... Args>
    auto product(Args... args) {
        return (args * ...);
    }
    ```

---

### **Template Specialization with Conditions**
21. **Q**: How do you specialize a class template for a specific condition?  
    **A**: By using traits or partial specialization. Example:
    ```cpp
    template <typename T>
    class Example {};

    template <>
    class Example<int> {
        void display() { cout << "Specialized for int" << endl; }
    };
    ```

22. **Q**: What is SFINAE?  
    **A**: "Substitution Failure Is Not An Error"—a mechanism where invalid substitutions of template parameters are ignored, allowing other overloads to be considered.

---

### **Template Deduction**
23. **Q**: What is class template argument deduction (CTAD)?  
    **A**: Automatically deducing template arguments from constructor parameters.

24. **Q**: Write an example of CTAD in action.  
    **A**:
    ```cpp
    template <typename T>
    class Example {
    public:
        Example(T val) {}
    };

    Example ex(42); // CTAD deduces T as int
    ```

---

### General Revision Questions

25. **Q**: What is the difference between `typename` and `class` in templates?  
    **A**: They are interchangeable in template declarations, but `typename` is preferred when working with dependent types.

26. **Q**: What are dependent types in templates?  
    **A**: Types that depend on a template parameter. Example:
    ```cpp
    template <typename T>
    class Example {
        typename T::type nestedType; // Dependent type
    };
    ```

27. **Q**: What is a non-type template parameter?  
    **A**: A template parameter that accepts values (e.g., `int`, `char`) instead of types.
    ```cpp
    template <int N>
    class Array {
        int data[N];
    };
    ```

28. **Q**: What are concepts (C++20)?  
    **A**: Constraints that specify requirements for template parameters:
    ```cpp
    template <typename T>
    requires std::integral<T>
    void print(T value) { cout << value << endl; }
    ```
