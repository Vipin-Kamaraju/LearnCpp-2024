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

=====================================================
---
# Example of `mutable` with const Class obj
=====================================================
---

When using the `mutable` keyword with class objects, it typically means that a data member, which is itself an instance of another class, is marked as mutable so that it can be modified in a `const` context. Essentially, you can use `mutable` to make entire class objects within another class modifiable, even if the containing object is declared `const`.

Below is a detailed example that shows how `mutable` can be applied to class objects and how it allows modifications.

### Notes about the code below
- If the `mutable` keyword was not used for `Logger logger` obj, the compiler would've given an error. Since `processData()` is a const member function, it can only call `const` functions to maintain **const-correctness**
- We can solve this in 2 ways:
	- **Solution 1:** use the keyword `mutable` to make the processData able to access a non-const function log() in Logger
    - **Solution 2:** declare the `log() const{}` function as const. This will maintain **const-correctness** and will not cause a compilation error.

### Example: Mutable Keyword with Class Objects

Suppose we have a scenario where we have a `Logger` class that logs messages, and we want to integrate this logger into a class. Even if the containing class instance is declared `const`, we still want to allow logging operations, which logically should not modify the state of the containing object. To achieve this, we can make the `Logger` class object mutable.

```cpp
#include <iostream>
#include <string>

class Logger {
public:
    void log(const std::string& message) {
        // Append the message to log (could be writing to a file or console)
        std::cout << "[LOG]: " << message << std::endl;
    }
};

class DataProcessor {
public:
    DataProcessor(const std::string& name) : name(name) {}

    void processData() const {
        // This is a const member function, but we can still log messages.
        logger.log("Processing data for " + name);
        // Do some processing here...
        logger.log("Finished processing data for " + name);
    }

private:
    std::string name;           // Name of the data being processed
    mutable Logger logger;      // Mutable logger object
};

int main() {
    const DataProcessor dp("ExampleData");
    dp.processData(); // Even though dp is const, we can still modify logger.

    return 0;
}
```

### Explanation

- **`Logger` Class**:
  - The `Logger` class provides a simple `log()` function to output log messages.
  
- **`DataProcessor` Class**:
  - The `DataProcessor` class has a `name` attribute and a `Logger` object called `logger`.
  - The `Logger` object (`logger`) is marked as `mutable`, which allows it to be modified even in `const` member functions.
  - `processData()` is declared as a `const` member function, which means it should not modify any non-mutable members of `DataProcessor`.
  
- **Usage in `main()`**:
  - The `DataProcessor` object (`dp`) is declared as `const`.
  - Despite the `dp` object being `const`, the `logger` is allowed to be used for logging because it is declared as `mutable`.

### Summary of Mutable Class Object Behavior

- By marking the `Logger` object as `mutable`, you can modify it even if the `DataProcessor` object is `const` and the function `processData()` is a `const` member function.
- This approach makes sense if the `Logger` object is used for purposes like logging or keeping debugging information, which does not logically affect the actual state of the `DataProcessor` but might still need modification internally.

### Example with a Mutex Class Object

Another practical example of using a mutable class object is with synchronization primitives like `std::mutex`. If you want to synchronize access to the data of a class even within `const` member functions, you can use `mutable std::mutex`:

```cpp
#include <iostream>
#include <string>
#include <mutex>

class ThreadSafeData {
public:
    ThreadSafeData(const std::string& data) : data(data) {}

    void displayData() const {
        std::lock_guard<std::mutex> lock(mtx); // `mtx` is mutable, allowing locking
        std::cout << "Data: " << data << std::endl;
    }

private:
    std::string data;            // Data to be displayed
    mutable std::mutex mtx;      // Mutable mutex for synchronization
};

int main() {
    const ThreadSafeData tsd("SensitiveData");
    tsd.displayData(); // Safe, even though tsd is const

    return 0;
}
```

- **`ThreadSafeData` Class**:
  - The `data` member holds some information.
  - The `mtx` member is a `std::mutex` declared as `mutable`.
  
- **Usage**:
  - Even though `displayData()` is a `const` member function, the `mutable` mutex (`mtx`) can still be locked to ensure thread safety.
  
### Summary of Compiler Interpretation of Mutable Class Objects

The compiler treats the `mutable` members as exceptions to the `const` rules:

- For any member marked as `mutable`, even if the containing object is `const`, the compiler allows modifications.
- This means the `this` pointer in a `const` function is interpreted as `const ClassName*` for all non-mutable members but allows mutable members to be modified.
  
In other words, if you have:

```cpp
const DataProcessor dp("ExampleData");
dp.processData();
```

- For `dp`, the member `logger` can still be modified because it's declared `mutable`.
- The compiler would generate code that allows calling non-`const` methods on `logger`, despite `dp` being declared `const`.

This use of `mutable` is beneficial for cases like caching, debugging, synchronization, and logging, which need modifications that do not change the primary state of an object and are considered auxiliary to the core logic.