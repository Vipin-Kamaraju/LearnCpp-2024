# For Loops

In modern C++ (C++11 and later), there are two common types of `for` loops:

### 1. **Traditional `for` Loop**
The traditional `for` loop is used when the number of iterations is known beforehand or for indexed iteration.

```cpp
for (initialization; condition; update) {
    // Loop body
}
```


### 2. **Range-Based `for` Loop** (Introduced in C++11)
The range-based `for` loop simplifies iteration over containers (like arrays, vectors, or lists) and ranges.

```cpp
for (element_type variable : container_or_range) {
    // Loop body
}
```

#### Example:
```cpp
#include <iostream>
#include <vector>
int main() {
    std::vector<int> numbers = {1, 2, 3, 4, 5};
    for (int num : numbers) {
        std::cout << num << " ";
    }
    return 0;
}
```

### 3. **Range-Based `for` Loop with References**
To avoid copying elements during iteration, especially for complex or large types, use references (`&`).

```cpp
for (auto& variable : container) {
    // Loop body
}
```

#### Example:
```cpp
#include <iostream>
#include <vector>
int main() {
    std::vector<int> numbers = {1, 2, 3, 4, 5};
    for (auto& num : numbers) {
        num *= 2; // Modify elements directly
    }
    return 0;
}
```

### 4. **Range-Based `for` Loop with `const`**
When elements should not be modified, use `const` with references.

```cpp
for (const auto& variable : container) {
    // Read-only loop body
}
```

#### Example:
```cpp
#include <iostream>
#include <vector>
int main() {
    const std::vector<int> numbers = {1, 2, 3, 4, 5};
    for (const auto& num : numbers) {
        std::cout << num << " ";
    }
    return 0;
}
```

### 5. **Using `for` Loops with Standard Library Algorithms (Optional)**
Though not a `for` loop, modern C++ often prefers standard library algorithms like `std::for_each` to iterate over containers.

```cpp
#include <iostream>
#include <vector>
#include <algorithm>
int main() {
    std::vector<int> numbers = {1, 2, 3, 4, 5};
    std::for_each(numbers.begin(), numbers.end(), [](int num) {
        std::cout << num << " ";
    });
    return 0;
}
```
- In the above example `[](int num) {std::cout << num << " ";}` is the `Lambda Function`

These syntax options cover most use cases for `for` loops in modern C++.

---
## Other related topics

- `Fold Expressions`
- `Lambda functions`
