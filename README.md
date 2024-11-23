# LearnCpp-2024 
This repository is a documentation of the C++ Programming Language. It covers a wide range of topics to become an expert in C++ programming

Modern C++ has evolved significantly, introducing a plethora of features and concepts that enhance performance, safety, and ease of programming. Below is a comprehensive classification of these concepts, grouped and sub-sectioned for clarity.

---

## 1. **Basic Concepts**

### 1.1 **Variables and Types**

- **Primitive Types**
  - `int`, `char`, `float`, `double`, `bool`
- **Type Modifiers**
  - `signed`, `unsigned`, `short`, `long`
- **User-Defined Types**
  - `struct`, `class`, `union`, `enum`

### 1.2 **Operators**

- **Arithmetic Operators**
  - `+`, `-`, `*`, `/`, `%`
- **Relational Operators**
  - `==`, `!=`, `<`, `>`, `<=`, `>=`
- **Logical Operators**
  - `&&`, `||`, `!`
- **Bitwise Operators**
  - `&`, `|`, `^`, `~`, `<<`, `>>`

### 1.3 **Control Flow**

- **Conditional Statements**
  - `if`, `else`, `switch`
- **Loops**
  - `for`, `while`, `do-while`
- **Jump Statements**
  - `break`, `continue`, `return`, `goto`

---

## 2. **Object-Oriented Programming (OOP)**

### 2.1 **Classes and Objects**

- **Class Declaration and Definition**
- **Access Specifiers**
  - `public`, `protected`, `private`
- **Constructors and Destructors**
- **Member Functions**
- **Friend Functions and Classes**

### 2.2 **Inheritance**

- **Types of Inheritance**
  - **Single Inheritance**
  - **Multiple Inheritance**
  - **Multilevel Inheritance**
  - **Hierarchical Inheritance**
  - **Hybrid (Virtual) Inheritance**

### 2.3 **Polymorphism**

#### 2.3.1 **Types of Polymorphism**

- **Compile-Time (Static) Polymorphism**
  - **Function Overloading**
  - **Operator Overloading**
  - **Templates**
- **Run-Time (Dynamic) Polymorphism**
  - **Virtual Functions**
  - **Abstract Classes**
  - **Interfaces**

#### 2.3.2 **Using Virtual Functions**

- **Overriding Member Functions**
- **Virtual Destructors**
- **Pure Virtual Functions**

### 2.4 **Encapsulation and Abstraction**

- **Data Hiding**
- **Interfaces and Abstract Classes**
- **Accessors and Mutators (Getters and Setters)**

---

## 3. **Templates and Generic Programming**

### 3.1 **Function Templates**

- **Generic Functions**
- **Type Deduction**

### 3.2 **Class Templates**

- **Generic Classes**
- **Template Specialization**
  - **Full Specialization**
  - **Partial Specialization**

### 3.3 **Variadic Templates**

- **Template Parameter Packs**
- **Recursive Template Instantiation**

### 3.4 **Concepts (Since C++20)**

- **Defining Constraints**
- **Using `requires` Clauses**

---

## 4. **Standard Template Library (STL)**

### 4.1 **Containers**

#### 4.1.1 **Sequence Containers**

- `vector`
- `list`
- `deque`
- `array`
- `forward_list`

#### 4.1.2 **Associative Containers**

- `set`, `multiset`
- `map`, `multimap`

#### 4.1.3 **Unordered Containers**

- `unordered_set`, `unordered_multiset`
- `unordered_map`, `unordered_multimap`

#### 4.1.4 **Container Adaptors**

- `stack`
- `queue`
- `priority_queue`

### 4.2 **Iterators**

- **Input Iterators**
- **Output Iterators**
- **Forward Iterators**
- **Bidirectional Iterators**
- **Random Access Iterators**

### 4.3 **Algorithms**

- **Non-modifying Sequence Operations**
- **Modifying Sequence Operations**
- **Sorting and Searching Algorithms**
- **Numeric Algorithms**

### 4.4 **Function Objects (Functors)**

- **Unary and Binary Function Objects**
- **Standard Function Objects**
- **Custom Functors**

### 4.5 **Allocators**

- **Default Allocators**
- **Custom Memory Allocation Strategies**

---

## 5. **Advanced Type Features**

### 5.1 **Type Inference**

- **`auto` Keyword**
- **`decltype` Keyword**

### 5.2 **Enumerations**

- **Unscoped Enums (`enum`)**
- **Scoped Enums (`enum class`)**

### 5.3 **Aliases**

- **Type Aliases with `typedef`**
- **Type Aliases with `using`**

### 5.4 **Structured Bindings (Since C++17)**

- **Decomposing Objects**
- **Binding to Tuple-Like Types**

---

## 6. **Memory Management**

### 6.1 **Dynamic Memory Allocation**

- **`new` and `delete` Operators**
- **`new[]` and `delete[]` Operators**

### 6.2 **Smart Pointers**

- **`std::unique_ptr`**
- **`std::shared_ptr`**
- **`std::weak_ptr`**
- **`std::auto_ptr` (Deprecated)**
- **`std::scoped_ptr` (Boost Library)**

### 6.3 **Memory Management Techniques**

- **RAII (Resource Acquisition Is Initialization)**
- **Memory Pools and Custom Allocators**
- **Garbage Collection (via Smart Pointers)**

### 6.4 **Move Semantics and Rvalue References**

- **Move Constructors**
- **Move Assignment Operators**
- **`std::move` and `std::forward`**

---

## 7. **Concurrency and Multithreading**

### 7.1 **Threads**

- **`std::thread` Class**
- **Creating and Managing Threads**
- **Thread Joining and Detaching**

### 7.2 **Synchronization Mechanisms**

- **Mutexes**
  - `std::mutex`
  - `std::recursive_mutex`
  - `std::timed_mutex`
  - `std::recursive_timed_mutex`
- **Locks**
  - `std::lock_guard`
  - `std::unique_lock`
  - `std::shared_lock` (Since C++14)
- **Condition Variables**
  - `std::condition_variable`
  - `std::condition_variable_any`

### 7.3 **Atomic Operations**

- **`std::atomic` Template**
- **Atomic Flags**
- **Memory Order Constraints**

### 7.4 **Futures and Promises**

- **`std::future` and `std::promise`**
- **Asynchronous Operations with `std::async`**

### 7.5 **Thread Local Storage**

- **`thread_local` Keyword**

---

## 8. **Functional Programming Features**

### 8.1 **Lambda Expressions**

- **Syntax and Capture Lists**
- **Lambda as Function Objects**
- **Generic Lambdas (Since C++14)**
- **Lambda Capture of `*this` (Since C++17)**

### 8.2 **std::function and std::bind**

- **Function Wrappers**
- **Binding Arguments to Functions**

### 8.3 **Higher-Order Functions**

- **Functions that Take Functions as Parameters**
- **Returning Functions from Functions**

---

## 9. **Compile-Time Programming**

### 9.1 **Constexpr**

- **`constexpr` Functions**
- **`constexpr` Variables**
- **`constinit` and `consteval` (Since C++20)**

### 9.2 **Metaprogramming**

- **Type Traits (`<type_traits>` Library)**
- **Compile-Time Computation**

### 9.3 **Concepts (Since C++20)**

- **Defining Concepts**
- **Constrained Templates**

---

## 10. **Error Handling**

### 10.1 **Exception Handling**

- **`try`, `catch`, `throw` Keywords**
- **Standard Exception Classes**
- **Custom Exception Classes**

### 10.2 **Noexcept Specifier**

- **`noexcept` Keyword**
- **`noexcept` Operator**

### 10.3 **Assertions**

- **`assert` Macro**
- **Static Assertions (`static_assert`)**

---

## 11. **Input/Output**

### 11.1 **Standard Streams**

- **`std::cin`, `std::cout`, `std::cerr`**
- **Stream Manipulators**

### 11.2 **File I/O**

- **File Streams (`std::ifstream`, `std::ofstream`, `std::fstream`)**

### 11.3 **String Streams**

- **`std::istringstream`, `std::ostringstream`, `std::stringstream`**

### 11.4 **Formatting (Since C++20)**

- **`std::format` Function**
- **Format Strings and Arguments**

---

## 12. **Advanced Language Features**

### 12.1 **Namespaces**

- **Defining and Using Namespaces**
- **Nested Namespaces**
- **Anonymous Namespaces**

### 12.2 **Preprocessor Directives**

- **Macros (`#define`)**
- **Include Guards (`#ifndef`, `#define`, `#endif`)**
- **Conditional Compilation (`#if`, `#ifdef`, `#endif`)**

### 12.3 **Attributes**

- **Standard Attributes (`[[nodiscard]]`, `[[maybe_unused]]`, etc.)**
- **Deprecated Attributes**

### 12.4 **User-Defined Literals**

- **Defining Literal Operators**
- **Using Suffixes for Custom Types**

---

## 13. **Standard Library Enhancements**

### 13.1 **Time Library (Since C++11)**

- **`<chrono>` Library**
- **Duration, Time Point, and Clock Types**

### 13.2 **Regular Expressions**

- **`<regex>` Library**
- **Pattern Matching and Searching**

### 13.3 **Random Number Generation**

- **Random Number Engines**
- **Random Number Distributions**

### 13.4 **Filesystem Library (Since C++17)**

- **`<filesystem>` Library**
- **Path Manipulation**
- **File and Directory Operations**

### 13.5 **Networking Library (Expected in C++23)**

- **Basic Sockets**
- **Networking Protocols**

---

## 14. **Type Safety and Type Manipulation**

### 14.1 **Strongly Typed Enumerations**

- **Scoped Enums (`enum class`)**

### 14.2 **Type Identification**

- **`typeid` Operator**
- **Run-Time Type Information (RTTI)**

### 14.3 **`std::any`, `std::variant`, and `std::optional`**

- **Type-Safe Containers for Heterogeneous Objects**

---

## 15. **Expressions and Statements Enhancements**

### 15.1 **Range-Based For Loop**

- **Iterating Over Containers**

### 15.2 **Initializer Lists**

- **Uniform Initialization Syntax**
- **`std::initializer_list`**

### 15.3 **Null Pointer Constant**

- **`nullptr` Keyword**

### 15.4 **Delegating Constructors**

- **Constructor Chaining**

### 15.5 **In-Class Member Initializers**

- **Default Member Initialization**

---

## 16. **Modern C++ Standards**

### 16.1 **C++11 Features**

- **Lambda Expressions**
- **Auto Type Deduction**
- **Rvalue References and Move Semantics**
- **Smart Pointers**

### 16.2 **C++14 Features**

- **Generic Lambdas**
- **Return Type Deduction**
- **Binary Literals**

### 16.3 **C++17 Features**

- **Structured Bindings**
- **If and Switch with Initializers**
- **Fold Expressions**

### 16.4 **C++20 Features**

- **Concepts**
- **Ranges Library**
- **Modules**
- **Coroutines**
- **Three-Way Comparison (`<=>` Operator)**

### 16.5 **C++23 and Beyond**

- **Expected Features**
  - **Reflection**
  - **Pattern Matching**
  - **Executor Framework**

---

## 17. **Best Practices and Design Patterns**

### 17.1 **RAII (Resource Acquisition Is Initialization)**

- **Managing Resources with Object Lifetimes**

### 17.2 **Rule of Three, Five, and Zero**

- **Copy Constructor**
- **Copy Assignment Operator**
- **Destructor**
- **Move Constructor (Rule of Five)**
- **Move Assignment Operator (Rule of Five)**

### 17.3 **Design Patterns**

- **Singleton**
- **Factory**
- **Observer**
- **Strategy**

### 17.4 **SOLID Principles**

- **Single Responsibility**
- **Open/Closed**
- **Liskov Substitution**
- **Interface Segregation**
- **Dependency Inversion**

---

## 18. **Testing and Debugging**

### 18.1 **Assertions**

- **`assert` Macro**
- **`static_assert`**

### 18.2 **Debugging Tools**

- **GDB**
- **Valgrind**

### 18.3 **Unit Testing Frameworks**

- **Google Test**
- **Catch2**

---

## 19. **Interoperability**

### 19.1 **C Compatibility**

- **`extern "C"` Declarations**
- **Linking with C Libraries**

### 19.2 **Interfacing with Other Languages**

- **Using SWIG**
- **C++/CLI for .NET Integration**

### 19.3 **Standard Library Interoperability**

- **Using C Libraries in C++**
- **Unicode and Localization**

---

## 20. **Compile-Time and Build Tools**

### 20.1 **Make and CMake**

- **Build Automation**
- **Project Configuration**

### 20.2 **Package Managers**

- **Conan**
- **Vcpkg**

### 20.3 **Continuous Integration**

- **Automated Testing**
- **Deployment Pipelines**

---

This classification covers the fundamental and advanced concepts of modern C++. Each section is designed to group similar concepts together, providing a structured overview of the language features and how they interrelate.
