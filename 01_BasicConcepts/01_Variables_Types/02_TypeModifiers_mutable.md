# `mutable` Keyword

In C++, the `mutable` keyword is used to allow modification of class member variables even if the containing object is marked as `const`. 

In simpler terms, when a `member function` is using `const` --> its `member variables` cannot be modified. In certain cases we might need to modify certain member variables inside the member function. For this purpose we use `mutable`.

`mutable` can be used in 2 ways provide acccess to member variables in :
- `const` member functions
- `const` class objects

### Purpose of the `mutable` Keyword
The primary purpose of `mutable` is to allow modification of specific data members in scenarios where the object is otherwise considered immutable. Typically, if an object is declared as `const`, none of its members can be modified. By marking a member with `mutable`, it allows that member to bypass this restriction.

### Use Cases for `mutable`
Here are some common scenarios where `mutable` is used:

1. **Caching and Lazy Evaluation**:
   - You might want to cache some computation results to avoid recomputation. To achieve this, a data member can be marked as `mutable` so it can be updated inside a `const` member function.

2. **Synchronization Mechanisms**:
   - `mutable` can be used to allow modification of synchronization primitives, such as `std::mutex`, even within a `const` context. This allows for thread-safe operations that don’t logically modify the state of the object.

3. **Statistics and Debug Information**:
   - You can use `mutable` for keeping counters, logging information, or debugging information that should not be part of the logical state of the object and should therefore be modifiable even in a `const` context.

4. **Auxiliary State**:
   - Sometimes you have auxiliary information that is not part of the primary state of the object. For example, you may have a flag indicating whether the primary data is valid, which can be recalculated even if the object is marked as `const`.

### Examples of Using `mutable`

Consider the following class examples demonstrating different scenarios for using `mutable`:

```cpp
#include <iostream>
#include <string>

class Example {
public:
    Example(std::string name) : name(name), accessCount(0) {}

    void display() const {
        // Allowed because accessCount is mutable
        ++accessCount;
        std::cout << "Name: " << name << ", Access Count: " << accessCount << std::endl;
    }

    void setName(const std::string& newName) {
        name = newName;
    }

private:
    std::string name;          // Normal member variable
    mutable int accessCount;   // Mutable variable (can change in const function)
};
```

In this example, `accessCount` is allowed to be modified even in the `const` member function `display()` because it is declared as `mutable`.

### Table of `mutable` Keyword Combinations

The following table shows the different ways in which `mutable` can be used, along with explanations:

| Use Case                  | Class Member Type | `const` Function | Mutable Member | Example Code                                                                 |
|---------------------------|-------------------|------------------|----------------|------------------------------------------------------------------------------|
| Basic Member Access       | Regular           | No               | No             | `void setName(const std::string& name);`                                     |
| Modify in `const` Context | Regular           | Yes              | Yes            | `mutable int accessCount;` in a class allows modification in a `const` method. |
| Synchronization           | Mutex (Auxiliary) | Yes              | Yes            | `mutable std::mutex mtx;` in a class allows locking within a `const` method. |
| Caching                   | Calculation Result| Yes              | Yes            | `mutable double cachedValue;` allows recalculating or caching in `const`.    |
| Thread Safety             | Atomic Counter    | Yes              | Yes            | `mutable std::atomic<int> counter;` allows updates in `const` for counting.  |

### Example of Combination Usage
```cpp
#include <mutex>
#include <string>

class DataCache {
public:
    std::string getData() const {
        // Use of mutable member in const function
        std::lock_guard<std::mutex> lock(mtx);
        if (!cached) {
            // Compute the value and update cache
            cachedData = computeExpensiveData();
            cached = true;
        }
        return cachedData;
    }

private:
    std::string computeExpensiveData() const {
        return "Expensive Data";
    }

    mutable std::mutex mtx;            // Mutex to ensure thread safety
    mutable std::string cachedData;    // Cache for computed data
    mutable bool cached = false;       // Flag indicating if cachedData is valid
};
```
- In the above example, `mtx`, `cachedData`, and `cached` are marked as `mutable` to enable modification in the `const` method `getData()`.


The use of `mutable` is powerful, but it must be used cautiously. It provides flexibility, but overusing it could compromise the const-correctness of your code and potentially lead to issues with understanding the intended immutability guarantees.