# Overview of Jump Statements in C++

Jump statements in C++ are used to transfer control to different parts of a program. They break the normal flow of execution and can be categorized into the following types:

---

### 1. **`break`**
- Exits the nearest enclosing loop or `switch` statement.
- Commonly used to terminate loops or prevent fall-through in `switch`.

##### Example:
```cpp
for (int i = 0; i < 10; ++i) {
    if (i == 5) break; // Exits the loop when i == 5
    std::cout << i << " ";
}
```

---

### 2. **`continue`**
- Skips the current iteration of the nearest enclosing loop and proceeds to the next iteration.

##### Example:
```cpp
for (int i = 0; i < 10; ++i) {
    if (i % 2 == 0) continue; // Skips even numbers
    std::cout << i << " ";
}
```

---

### 3. **`return`**
- Exits from the current function and optionally returns a value to the caller.
- Essential for defining the outcome of a function.

##### Example:
```cpp
int add(int a, int b) {
    return a + b; // Returns the sum
}
```

---

### 4. **`goto`**
- Transfers control unconditionally to a labeled statement.
- Rarely used in modern C++ due to readability and maintainability concerns.

##### Example:
```cpp
int i = 0;
start:
if (i < 5) {
    std::cout << i++ << " ";
    goto start; // Jumps back to the label
}
```

---

### Best Practices
- Use `break` and `continue` judiciously for clarity in loops.
- Prefer structured flow control over `goto`.
- Use `return` to provide clear function outcomes, ensuring maintainable and predictable code.

These jump statements offer flexibility in controlling program execution, but overuse or misuse can lead to convoluted and hard-to-read code.