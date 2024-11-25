The syntax for `std::for_each` in C++ is as follows:

```cpp
std::for_each(InputIterator first, InputIterator last, Function func);
```

### **Parameters**
1. **`InputIterator first`:**  
   - The iterator pointing to the beginning of the range.
2. **`InputIterator last`:**  
   - The iterator pointing one past the last element in the range.
3. **`Function func`:**  
   - A callable object (e.g., function, function pointer, or lambda expression) that will be applied to each element in the range `[first, last)`.

---

### **Basic Example**
```cpp
#include <iostream>
#include <vector>
#include <algorithm> // For std::for_each

int main() {
    std::vector<int> numbers = {1, 2, 3, 4, 5};

    // Using std::for_each with a lambda
    std::for_each(numbers.begin(), numbers.end(), [](int num) {
        std::cout << num << " ";
    });

    return 0;
}
```
**Output:**
```
1 2 3 4 5
```

---

### **Detailed Explanation**
1. **Iterators (`first` and `last`):**
   - These define the range over which `std::for_each` operates.
   - It will process elements starting from `first` and ending just before `last`.

2. **Function (`func`):**
   - This is the action to perform on each element. It can be:
     - A regular function.
     - A function pointer.
     - A functor (an object with `operator()` defined).
     - A lambda function (most common in modern C++).

---

### **Using a Regular Function**
```cpp
#include <iostream>
#include <vector>
#include <algorithm>

// Regular function to print a number
void printNumber(int num) {
    std::cout << num << " ";
}

int main() {
    std::vector<int> numbers = {1, 2, 3, 4, 5};

    std::for_each(numbers.begin(), numbers.end(), printNumber);

    return 0;
}
```

---

### **Using a Functor**
```cpp
#include <iostream>
#include <vector>
#include <algorithm>

// Functor
class MultiplyAndPrint {
    int factor;
public:
    MultiplyAndPrint(int f) : factor(f) {}
    void operator()(int num) const {
        std::cout << num * factor << " ";
    }
};

int main() {
    std::vector<int> numbers = {1, 2, 3, 4, 5};

    std::for_each(numbers.begin(), numbers.end(), MultiplyAndPrint(2));

    return 0;
}
```
**Output:**
```
2 4 6 8 10
```

---

### **Using a Lambda Function**
Lambda functions are the most concise and readable way to define inline behavior. 

#### Example: Print Elements
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

#### Example: Modify Elements
You can modify the elements by capturing variables by reference:
```cpp
#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::vector<int> numbers = {1, 2, 3, 4, 5};

    std::for_each(numbers.begin(), numbers.end(), [](int& num) {
        num *= 2; // Double each element
    });

    for (int num : numbers) {
        std::cout << num << " ";
    }

    return 0;
}
```
**Output:**
```
2 4 6 8 10
```

---

### **Return Value**
The return value of `std::for_each` in C++11 and later is a copy of the `Function` passed to it. This is useful when the `Function` is stateful, such as a functor or a lambda with a captured state.

#### Example: Capturing a Result
```cpp
#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::vector<int> numbers = {1, 2, 3, 4, 5};

    int sum = 0;
    auto result = std::for_each(numbers.begin(), numbers.end(), [&sum](int num) {
        sum += num; // Accumulate sum
    });

    std::cout << "Sum: " << sum << std::endl;

    return 0;
}
```
**Output:**
```
Sum: 15
```

---

### **C++20: `std::ranges::for_each`**
C++20 introduced a more powerful version called `std::ranges::for_each`, which works with ranges directly instead of requiring iterators.

#### Example:
```cpp
#include <iostream>
#include <vector>
#include <ranges>

int main() {
    std::vector<int> numbers = {1, 2, 3, 4, 5};

    std::ranges::for_each(numbers, [](int num) {
        std::cout << num << " ";
    });

    return 0;
}
```

This avoids the need for `begin()` and `end()` explicitly, making the code cleaner.

---

### **Summary**
- **Basic Syntax:**
  ```cpp
  std::for_each(InputIterator first, InputIterator last, Function func);
  ```
- **Common Usage:**
  - Regular functions
  - Function pointers
  - Functors
  - Lambdas (most modern usage)
- **Modern Alternative:** `std::ranges::for_each` in C++20 simplifies usage with ranges.

Let me know if you'd like more details or examples!