### Summary of Topics Discussed with Examples

---

### 1. **Basic Templates**
- Templates allow you to write generic code that works with any data type.
- **Function Template**:
  ```cpp
  template <typename T>
  T add(T a, T b) {
      return a + b;
  }

  int main() {
      cout << add(3, 4) << endl;       // Output: 7
      cout << add(3.1, 4.2) << endl;  // Output: 7.3
  }
  ```
- **Class Template**:
  ```cpp
  template <typename T>
  class Calculator {
      T a, b;
  public:
      Calculator(T x, T y) : a(x), b(y) {}
      T add() { return a + b; }
  };

  int main() {
      Calculator<int> calc(3, 4);
      cout << calc.add() << endl; // Output: 7
  }
  ```

---

### 2. **Template Specialization**
- Allows tailoring templates for specific types.
- **Full Specialization**:
  ```cpp
  template <typename T>
  class Printer {
  public:
      void print(T value) { cout << value << endl; }
  };

  template <>
  class Printer<char> {
  public:
      void print(char value) { cout << "Char: " << value << endl; }
  };

  int main() {
      Printer<int> p1;
      p1.print(42); // Output: 42

      Printer<char> p2;
      p2.print('A'); // Output: Char: A
  }
  ```

---

### 3. **Variadic Templates**
- Handle an arbitrary number of arguments.
- **Recursive Example**:
  ```cpp
  template <typename T>
  void print(T value) {
      cout << value << " ";
  }

  template <typename T, typename... Args>
  void print(T value, Args... args) {
      cout << value << " ";
      print(args...);
  }

  int main() {
      print(1, 2.5, "Hello", 'A'); // Output: 1 2.5 Hello A
  }
  ```

- **Fold Expression (C++17)**:
  ```cpp
  template <typename... Args>
  void print(Args... args) {
      ((cout << args << " "), ...);
      cout << endl;
  }

  int main() {
      print(1, 2.5, "Hello", 'A'); // Output: 1 2.5 Hello A
  }
  ```

---

### 4. **Template Metaprogramming**
- Perform computations at compile time.
- **Factorial Example**:
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

  int main() {
      cout << Factorial<5>::value << endl; // Output: 120
  }
  ```

- **Fibonacci Example**:
  ```cpp
  template <int N>
  class Fibonacci {
  public:
      static constexpr int value = Fibonacci<N - 1>::value + Fibonacci<N - 2>::value;
  };

  template <>
  class Fibonacci<0> {
  public:
      static constexpr int value = 0;
  };

  template <>
  class Fibonacci<1> {
  public:
      static constexpr int value = 1;
  };

  int main() {
      cout << Fibonacci<10>::value << endl; // Output: 55
  }
  ```

---

### 5. **Type Traits and `std::enable_if`**
- Restrict template usage based on type properties.
- **Using `std::enable_if`**:
  ```cpp
  #include <type_traits>
  template <typename T>
  typename std::enable_if<std::is_integral<T>::value, void>::type
  printIfIntegral(T value) {
      cout << value << " is an integer" << endl;
  }

  int main() {
      printIfIntegral(5);       // Output: 5 is an integer
      // printIfIntegral(3.14); // Compile-time error
  }
  ```

- **Custom Type Trait**:
  ```cpp
  #include <type_traits>
  template <typename T>
  struct is_pointer {
      static constexpr bool value = false;
  };

  template <typename T>
  struct is_pointer<T*> {
      static constexpr bool value = true;
  };

  int main() {
      cout << is_pointer<int>::value << endl;   // Output: 0
      cout << is_pointer<int*>::value << endl; // Output: 1
  }
  ```

---

### 6. **CRTP (Curiously Recurring Template Pattern)**
- Used for static polymorphism.
- **Example**:
  ```cpp
  template <typename Derived>
  class Base {
  public:
      void interface() {
          static_cast<Derived*>(this)->implementation();
      }
  };

  class Derived : public Base<Derived> {
  public:
      void implementation() { cout << "Derived implementation" << endl; }
  };

  int main() {
      Derived d;
      d.interface(); // Output: Derived implementation
  }
  ```

---

### 7. **Fold Expressions**
- Simplify operations on variadic arguments (C++17).
- **Example**:
  ```cpp
  template <typename... Args>
  auto sumAll(Args... args) {
      return (args + ...); // Expands to: arg1 + arg2 + ... + argN
  }

  int main() {
      cout << sumAll(1, 2, 3, 4) << endl; // Output: 10
  }
  ```

---

### 8. **Template Specialization with Conditions**
- **Partial Specialization**:
  ```cpp
  template <typename T, typename U>
  class Example {};

  template <typename T>
  class Example<T, int> {
  public:
      void display() { cout << "Specialized for int" << endl; }
  };

  int main() {
      Example<double, int> obj;
      obj.display(); // Output: Specialized for int
  }
  ```

---
