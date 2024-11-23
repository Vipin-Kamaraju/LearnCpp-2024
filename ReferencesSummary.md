# Types of References
---

### **References Summary Table**

| **Reference Type**              | **Declaration**                         | **Example**                                                                                      | **Explanation**                                                                                                                |
|----------------------------------|-----------------------------------------|--------------------------------------------------------------------------------------------------|-------------------------------------------------------------------------------------------------------------------------------|
| **Reference**                   | `Type& ref = var;`                      | ```cpp int x = 10; int& ref = x; ref = 20; ```                                                  | A reference to an existing variable. Must be initialized and cannot be reseated to another variable.                         |
| **Const Reference**              | `const Type& ref = var;`                | ```cpp int x = 10; const int& ref = x; ref = 20; // Error ```                                   | A reference that cannot modify the value of the referenced variable.                                                          |
| **Rvalue Reference**             | `Type&& ref = expr;`                    | ```cpp int&& ref = 10; ref = 20; ```                                                            | A reference to a temporary (rvalue). Useful in move semantics for efficient resource management.                              |
| **Reference to Pointer**         | `Type*& ref = ptr;`                     | ```cpp int x = 10; int* ptr = &x; int*& ref = ptr; ```                                          | A reference to a pointer, allowing modification of the pointer itself and the value it points to.                             |
| **Const Reference to Pointer**   | `const Type* const& ref = ptr;`         | ```cpp int x = 10; int* ptr = &x; const int* const& ref = ptr; ```                              | A reference to a const pointer that cannot modify the pointer or the value it points to.                                       |
| **Null Reference (Invalid)**     | N/A                                     | ```cpp int& ref = nullptr; // Error ```                                                        | References cannot be null. Attempting to create a null reference results in a compile-time error.                             |
| **Reference to Const**           | `const Type& ref = var;`                | ```cpp int x = 10; const int& ref = x; ```                                                     | A reference that ensures the referenced value cannot be modified.                                                             |

---

- Do not reference rvalues from function returns since once the function is destroyed the reference is also automatically destroyed.