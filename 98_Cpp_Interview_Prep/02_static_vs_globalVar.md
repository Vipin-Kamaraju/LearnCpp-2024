## Why not just use a global variable instead of a `static` member variable, since it's declared outside the class anyway?

## ✅ Why Not Just Use a Global Variable?

### Example 1: Global Variable

```cpp
int count = 0;

void increment() {
    ++count;
    std::cout << "Count: " << count << std::endl;
}
```

### Example 2: Static Member in a Class

```cpp
class Counter {
private:
    static int count; // Step 2 : Defining the scope to the class
public:
    static void increment() {
        ++count; // Step 3 : Can increment only from within the class
        std::cout << "Count: " << count << std::endl;
    }
};

int Counter::count = 0; // Step 1 : Initialize and allocate storage
```

### Example 3: Using inline
- When we want to avoid decalration outside the Class this is possible with a new feature in C++17 using inline as shown below

```cpp
class Counter {
private:
    inline static int count = 0; // Step 1 : Init + Global Storage + Class Scope
public:
    static void increment() {
        ++count; // Step 3 : Can increment only from within the class
        std::cout << "Count: " << count << std::endl;
    }
};
```

---

## 🧩 Key Differences and Why `static` in Class is Better

| Feature | Global Variable | Static Member Variable |
|--------|------------------|------------------------|
| **Encapsulation** | ❌ Anyone can access it from anywhere. | ✅ Only accessible via `Counter::count`. |
| **Namespace Pollution** | ❌ Clutters global scope. | ✅ Organized inside the class scope. |
| **Type Context** | ❌ Not associated with any logical type. | ✅ Tied to a class or concept (Counter). |
| **OOP Design** | ❌ Breaks encapsulation and modularity. | ✅ Encourages clean object-oriented design. |
| **Reusability** | ❌ Not reusable across types or modules. | ✅ You can have `Counter`, `Logger`, `Metrics`, etc. each with their own static state. |
| **Unit Testing / Mocking** | ❌ Hard to isolate or test. | ✅ Easy to encapsulate, reset, or override in class-based mocks. |
| **Thread Safety** (C++11+) | ❓ Possible, but needs more care. | ✅ You can encapsulate sync logic inside the class. |

---

## 💡 Think of `static` in Classes As:

> “A **global** variable that is **scoped, owned, and logically attached** to a class.”

It’s a **controlled global** — part of the class’s interface, not the universe’s.

---
