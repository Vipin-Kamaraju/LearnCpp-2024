# `switch` Statements in Modern C++

In C++, the `switch` statement is a control flow structure used to execute one block of code among many based on the value of an expression. Unlike if-else chains, `switch` is often more readable and can provide more optimized branching, especially when the cases are known at compile-time.

---

### **Syntax Overview**

A `switch` statement consists of:
1. **Expression**: A value evaluated once at runtime.
2. **Cases**: Specific values to compare against the expression.
3. **`break` Statements**: Prevents fall-through behavior.
4. **Default Case**: A catch-all block if no cases match.

```cpp
switch (expression) {
    case value1:
        // Code for value1
        break;
    case value2:
        // Code for value2
        break;
    default:
        // Code if none of the cases match
        break;
}
```

---