# Common algorithms used for Bitwise manipulation

Bitwise operations are powerful tools in programming, especially for optimizing solutions in coding interviews. Below is a comprehensive list of common bitwise operation formulas and techniques, along with explanations and C++ examples to help you tackle interview questions more efficiently.

---

### 1. **Check if a Number is Even or Odd**
**Formula:**
```cpp
bool isOdd = num & 1;
```
**Explanation:**
- The least significant bit (LSB) determines the parity.
- If `num & 1` is `1`, the number is odd; otherwise, it's even.

**Example:**
```cpp
int num = 5;
if (num & 1)
    cout << "Odd";
else
    cout << "Even";
```

---

### 2. **Check if a Number is a Power of Two**
**Formula:**
```cpp
bool isPowerOfTwo = (num > 0) && ((num & (num - 1)) == 0);
```
**Explanation:**
- A power of two has only one set bit.
- `num & (num - 1)` removes the rightmost set bit. If the result is `0`, it's a power of two.

**Example:**
```cpp
int num = 16;
bool result = (num > 0) && ((num & (num - 1)) == 0);
cout << (result ? "Power of Two" : "Not a Power of Two");
```

---

### 3. **Count the Number of Set Bits (1s)**
**Method 1: Iterative Approach**
```cpp
int countSetBits(int num) {
    int count = 0;
    while (num) {
        count += num & 1;
        num >>= 1;
    }
    return count;
}
```

**Method 2: Brian Kernighan’s Algorithm**
```cpp
int countSetBits(int num) {
    int count = 0;
    while (num) {
        num &= (num - 1);
        count++;
    }
    return count;
}
```
**Explanation:**
- **Iterative Approach:** Shift bits right and count the number of `1`s.
- **Brian Kernighan’s:** Efficiently reduces the number of operations by turning off the rightmost set bit each iteration.

**Example:**
```cpp
int num = 29; // Binary: 11101
cout << "Set Bits: " << countSetBits(num);
```

---

### 4. **Reverse Bits of an Integer**

- Reverse bits is different operation vs flipping bits
- For flipping or inverting bits we can use the `~` operator

For example, reversing the bits of `5`:
- Binary representation of `5`:
  ```
  00000000 00000000 00000000 00000101
  ```
- Reversed bit order:
  ```
  10100000 00000000 00000000 00000000
  ```

This is a reordering, not a bitwise inversion.

**Steps:**
1. Initialize `result` to `0`.
2. Iterate through each bit:
   - Shift `result` left by 1.
   - Add the LSB of `num` to `result`.
   - Shift `num` right by 1.

**Formula:**
```cpp
unsigned int reverseBits(unsigned int num) {
    unsigned int result = 0;
    for(int i = 0; i < 32; i++) {
        result <<= 1;
        result |= (num & 1);
        num >>= 1;
    }
    return result;
}
```

**Example:**
```cpp
unsigned int num = 43261596;
cout << "Reversed Bits: " << reverseBits(num);
```

---

### 5. **Swap Two Numbers Without a Temporary Variable**
**Formula:**
```cpp
a = a ^ b;
b = a ^ b;
a = a ^ b;
```
**Explanation:**
- XOR swapping eliminates the need for a temporary variable by leveraging the properties of XOR.

**Example:**
```cpp
int a = 5, b = 9;
a = a ^ b;
b = a ^ b; // b becomes 5
a = a ^ b; // a becomes 9
cout << "a: " << a << ", b: " << b;
```

---

### 6. **Isolate the Rightmost Set Bit**
**Formula:**
```cpp
int isolateRightmostSetBit = num & (-num);
```
**Explanation:**
- `-num` is the two’s complement of `num`. `num & (-num)` isolates the rightmost `1` bit.

**Example:**
```cpp
int num = 12; // Binary: 1100
cout << "Isolated Bit: " << (num & -num); // Outputs 4
```
- **Example:**
  - If `n = 10` (binary `1010`), then `n & (-n)` gives `2` (binary `0010`).
  - If `n = 12` (binary `1010`), then `n & (-n)` gives `4` (binary `0010`).
  - If `n = 18` (binary `10010`), then `n & (-n)` gives `2` (binary `0010`).
  

---

### 7. **Clear the Rightmost Set Bit**
**Formula:**
```cpp
num = num & (num - 1);
```
**Explanation:**
- This operation removes the rightmost set bit from `num`.

**Example:**
```cpp
int num = 14; // Binary: 1110
num = num & (num - 1); // num becomes 12 (1100)
cout << "After Clearing: " << num;
```

---

### 8. **Set the Rightmost Unset Bit**
**Formula:**
```cpp
num = num | (num + 1);
```
**Explanation:**
- `num + 1` flips the rightmost unset bit and all bits to its right.
- OR-ing with `num` sets that bit.

**Example:**
```cpp
int num = 10; // Binary: 1010
num = num | (num + 1); // num becomes 1011 (11)
cout << "After Setting: " << num;
```

---

### 9. **Check if Two Integers Have Opposite Signs**
**Formula:**
```cpp
bool oppositeSigns = (a ^ b) < 0;
```
**Explanation:**
- XOR of two numbers with opposite signs will have the sign bit set (negative).
- **Case 1: Same Sign both positive** MSB bits are 0's --> `0 ^ 0` --> MSB of `(a^b)` is `0` --> positive number --> greater than 0
- **Case 2: Same sign both negative** MSB bits are 1's --> `1 ^ 1` --> MSB of `(a^b)` `0` --> positive number --> greater than 0
- **Case 3: Opposite Sign** MSB bits are 0 and 1 --> `0 ^ 1` (vice versa also same) --> MSB of `(a^b)` `1` --> negative number --> less than 0

**Example:**
```cpp
int a = -5, b = 10;
bool result = (a ^ b) < 0;
cout << (result ? "Opposite Signs" : "Same Signs");
```

---

### 10. **Find the Single Number in an Array (All Others Appear Twice)**
**Formula:**
```cpp
int singleNumber(vector<int>& nums) {
    int result = 0;
    for(auto num : nums)
        result ^= num;
    return result;
}
```
**Explanation:**
- XOR-ing all numbers cancels out the duplicates, leaving the single number.

This algorithm leverages the properties of the XOR (`^`) operation to efficiently find the single number in an array where every other number appears exactly twice. Let’s break it down step by step.

### **Key XOR Properties**
1. **Identity**: `x ^ 0 = x` --> XOR-ing a number with `0` leaves the number unchanged.

2. **Self-Inverse**: `x ^ x = 0` --> XOR-ing a number with itself results in `0`.

3. **Commutativity and Associativity**: Order doesn’t matter in XOR operations: `x^y = y^x`, and `(x^y)^z = x^(y^z)`.


### **How the Algorithm Works**
Given an array where every number appears twice except one, XOR-ing all the numbers cancels out the duplicates because of the self-inverse property `(x ^ x = 0)`.

#### Steps:
1. Initialize `result = 0`.
2. XOR all numbers in the array. Duplicates cancel out, leaving only the single number.

#### Example:
```cpp
vector<int> nums = {2, 3, 2, 4, 4};
```

1. Initialize `result = 0`.
2. Process each number in `nums`:
   - \( result = result \oplus 2 = 0 \oplus 2 = 2 \)
   - \( result = result \oplus 3 = 2 \oplus 3 = 1 \)
   - \( result = result \oplus 2 = 1 \oplus 2 = 3 \)
   - \( result = result \oplus 4 = 3 \oplus 4 = 7 \)
   - \( result = result \oplus 4 = 7 \oplus 4 = 3 \)

3. After XOR-ing all numbers, `result = 3`.

**Final Result: The single number is `3`.**

### **Why XOR Works**
- Duplicates cancel out due to the self-inverse property `x^x = 0`.
- The single number remains because XOR-ing with `0` leaves it unchanged `x^0 = x`.

### **Complexity**
1. **Time Complexity**: \( O(n) \)
   - The algorithm iterates through the array once, performing an \( O(1) \) XOR operation for each element.

2. **Space Complexity**: \( O(1) \)
   - No additional memory is used; everything happens in-place.

### **Advantages**
- Efficient and simple, relying solely on the XOR operation.
- Avoids the need for sorting or additional data structures like hash maps.

### **Edge Cases**
1. **Array of Size 1**:
   - Input: `nums = {42}`
   - Output: `42`
   - Explanation: The single number is returned as-is.

2. **Large Arrays with Random Order**:
   - XOR is commutative and associative, so the order doesn’t matter.

3. **Negative Numbers**:
   - Works seamlessly because XOR operates on the binary representation, which is the same for signed integers.

---

### 11. **Determine if a Number has an Even Number of Set Bits**
**Formula:**
```cpp
bool hasEvenSetBits = (countSetBits(num) % 2 == 0);
```
**Explanation:**
- Utilize the `countSetBits` function and check if the count is even.

**Example:**
```cpp
int num = 7; // Binary: 0111
bool result = (countSetBits(num) % 2 == 0);
cout << (result ? "Even Set Bits" : "Odd Set Bits");
```

---

### 12. **Find the Position of the Rightmost Set Bit**
**Formula:**
```cpp
int position = log2(num & -num) + 1;
```
**Explanation:**
- `num & -num` isolates the rightmost set bit.
- Taking the logarithm base 2 gives the position (0-indexed). Add 1 for 1-indexed.

**Example:**
```cpp
int num = 18; // Binary: 10010
int position = log2(num & -num) + 1; // Position 2
cout << "Position: " << position;
```

---

### 13. **Swap Even and Odd Bits**
**Steps:**
1. Mask even bits and shift them right.
2. Mask odd bits and shift them left.
3. Combine the results using OR.

**Formula:**
```cpp
unsigned int swapEvenOddBits(unsigned int num) {
    unsigned int evenMask = 0xAAAAAAAA;
    unsigned int oddMask = 0x55555555;
    return ((num & evenMask) >> 1) | ((num & oddMask) << 1);
}
```

**Example:**
```cpp
unsigned int num = 23; // Binary: 00010111
cout << "Swapped Bits: " << swapEvenOddBits(num); // Outputs 43 (00101011)
```
#### **Explanation:**

1. **Even and Odd Bits in Binary**:
   - Even-numbered bits are bits at positions `0, 2, 4, 6, ...` (0-indexed).
   - Odd-numbered bits are bits at positions `1, 3, 5, 7, ...` (0-indexed).

2. **Masks Used**:
   - `evenMask = 0xAAAAAAAA`:
     - Binary: `10101010101010101010101010101010`
     - This selects only the even bits.
   - `oddMask = 0x55555555`:
     - Binary: `01010101010101010101010101010101`
     - This selects only the odd bits.

3. **Steps in the Formula**:
   - **Mask Even Bits**: Use `num & evenMask` to isolate the even bits, then shift them right by `1` to move them to the odd positions.
   - **Mask Odd Bits**: Use `num & oddMask` to isolate the odd bits, then shift them left by `1` to move them to the even positions.
   - **Combine Results**: Use the bitwise OR operator (`|`) to merge the modified even and odd bits.


---

### 14. **Find Missing Number in a Sequence**


**Question** : Assume we have n unique integers from 1 to n in an vector array. Find the missing number in the sequence. (Assume no numbers are repeated, no negative numbers)

**Steps:**
- We will use the Identity, Self-inverse and Associative logic of XOR as shown in ref.10
- First we will loop through all integers and perform XOR operation --> x1
- Then we will iterate through all the elements of vector and perform XOR --> x2
- `x1 ^ x2` will give us the missing integer

**Formula:**
```cpp
int findMissingNumber(vector<int>& nums, int n) {
    int x1 = 0;
    for(int i = 1; i <= n; i++) x1 ^= i;
    int x2 = 0;
    for(auto num : nums) x2 ^= num;
    return x1 ^ x2;
}
```

**Example:**
```cpp
vector<int> nums = {1, 2, 4, 5};
int n = 5;
cout << "Missing Number: " << findMissingNumber(nums, n); // Outputs 3
```


---

### 15. **Find the Two Non-Repeating Elements in an Array**
**Steps:**
1. XOR all elements to get XOR of the two unique numbers.
2. Find a set bit in the XOR result to divide numbers into two groups.
3. XOR each group to get the unique numbers.

**Formula:**
```cpp
pair<int, int> findTwoUniqueNumbers(vector<int>& nums) {
    int xor_all = 0;
    for(auto num : nums) xor_all ^= num;
    int set_bit = xor_all & (-xor_all);
    int x = 0, y = 0;
    for(auto num : nums){
        if(num & set_bit)
            x ^= num;
        else
            y ^= num;
    }
    return {x, y};
}
```

**Example:**
```cpp
vector<int> nums = {2, 4, 7, 9, 2, 4};
pair<int, int> result = findTwoUniqueNumbers(nums);
cout << "Unique Numbers: " << result.first << " and " << result.second;
```

#### **Steps**

1. **XOR All Numbers:** XOR all elements in the array. The result (`xor_all`) is the XOR of the two unique numbers because all duplicate numbers cancel out.

2. We can use the **Two's compliment** to isolate the rightmost bit in the `xor_all`. This will be used as a **mask (set_bit)** to seperate the vector into 2 groups as shown in the if-else loop in code.
3. ***Find a Set Bit in `xor_all`**
   - The XOR result `xor_all` will have at least one bit set, corresponding to a bit where the two unique numbers differ.
   - Use `xor_all & (-xor_all)` to isolate the rightmost set bit. This set bit is used to divide the numbers into two groups.

4. **Group and XOR**
   - Partition the numbers into two groups based on whether they have the isolated bit set (`num & set_bit`).
   - XOR the numbers in each group. Each group will cancel out duplicates, leaving one unique number per group.

5. The `set_bit` mask is the key difference between the 2 numbers

#### **Code Walkthrough**

#### Input:
```cpp
vector<int> nums = {2, 4, 7, 9, 2, 4};
```

1. **Step 1: XOR All Numbers**
   ```cpp
   int xor_all = 0;
   for (auto num : nums) xor_all ^= num;
   ```
   **XOR of all elements**:
   ```
   xor_all = 2 ^ 4 ^ 7 ^ 9 ^ 2 ^ 4
           = 7 ^ 9
           = 14 (binary: 1110)
   ```

2. **Step 2: Find a Set Bit in `xor_all`**
   ```cpp
   int set_bit = xor_all & (-xor_all);
   ```
   - `-xor_all` is the two's complement of `xor_all`, flipping all bits and adding `1`.
   - **`xor_all = 1110`** → **`-xor_all = 0010`**
   - **`xor_all & -xor_all = 0010`**
   - This isolates the rightmost set bit: `2` (binary `0010`).

3. **Step 3: Divide Numbers into Two Groups**
   ```cpp
   int x = 0, y = 0;
   for (auto num : nums) {
       if (num & set_bit)
           x ^= num;
       else
           y ^= num;
   }
   ```
   - **Group 1 (`num & set_bit != 0`)**:
     - Numbers with the isolated bit set: `{2, 2, 7}`
     - XOR of this group: `x = 2 ^ 2 ^ 7 = 7`

   - **Group 2 (`num & set_bit == 0`)**:
     - Numbers with the isolated bit not set: `{4, 4, 9}`
     - XOR of this group: `y = 4 ^ 4 ^ 9 = 9`

4. **Result**:
   ```cpp
   return {x, y}; // {7, 9}
   ```

#### **Example Output**
For the input:
```cpp
vector<int> nums = {2, 4, 7, 9, 2, 4};
```

Output:
```
Unique Numbers: 7 and 9
```


---

### 16. **Determine if Two Integers are Bitwise Anagrams**
**Explanation:**
- Two numbers are bitwise anagrams if they have the same number of set bits.

**Formula:**
```cpp
bool areBitwiseAnagrams(int a, int b) {
    return countSetBits(a) == countSetBits(b);
}
```

**Example:**
```cpp
int a = 5; // Binary: 0101
int b = 3; // Binary: 0011
cout << (areBitwiseAnagrams(a, b) ? "Anagrams" : "Not Anagrams");
```

---

### 17. **Find the Bit Position of the Only Set Bit**
**Formula:**
```cpp
int findSetBitPosition(int num) {
    if(num == 0) return -1;
    return log2(num) + 1;
}
```
**Explanation:**
- Use logarithm to find the position of the single set bit.

**Example:**
```cpp
int num = 16; // Binary: 10000
cout << "Set Bit Position: " << findSetBitPosition(num); // Outputs 5
```

---

### **Additional Tips:**
- **Understanding Two's Complement:** Negative numbers are represented using two's complement. This is crucial when performing operations like `num & -num`.
- **Bit Masks:** Creating masks using hexadecimal (e.g., `0xFF`, `0x0F`) can help in isolating or modifying specific bits.
- **Shifting Operators:** Left shift (`<<`) and right shift (`>>`) are fundamental for moving bits and can be combined with masks for various operations.
- **Subtract 1 from n:** When we subtract 1 from n, we end up changing the rightmost set bit to 0 and flipping all the bits to the right of it.
- **Two's Compliment:** 
	- Used to isolate the rightmost set bit
    - Used to find the position of rightmost set bit by isolating and then using log2
- **Built-in Functions:** Familiarize yourself with compiler-specific built-in functions like `__builtin_popcount`, `__builtin_clz`**(leading 0's)**, and `__builtin_ctz`**(trailing 0's)** for GCC/Clang.


==================================================
---
## Other Algorithms
==================================================
---

### **1. Set the `k`th Bit**
- **Formula:** `n | (1 << (k - 1))`
- **Explanation:** Sets the `k`th bit to `1`.

### **2. Toggle the `k`th Bit**
- **Formula:** `n ^ (1 << (k - 1))`
- **Explanation:** Flips the value of the `k`th bit.

### **3. Check if `k`th Bit is Set**
- **Formula:** `(n & (1 << (k - 1))) != 0`
- **Explanation:** Checks whether the `k`th bit is set.

### **4. Multiply a Number by Power of 2**
- **Formula:** `n << k` 
  - Where `k` is the power.
- **Explanation:** Left-shifting `n` by `k` is equivalent to multiplying `n` by `2^k`.

### **5. Divide a Number by Power of 2**
- **Formula:** `n >> k` 
  - Where `k` is the power.
- **Explanation:** Right-shifting `n` by `k` is equivalent to dividing `n` by `2^k`.

### **6. Clear All Bits from the Least Significant Bit to `k`th Bit (inclusive)**
- **Formula:** `n & ~((1 << k) - 1)`
- **Explanation:** Clears all bits from the least significant bit to the `k`th bit.

### **7. Clear All Bits from the Most Significant Bit to `k`th Bit**
- **Formula:** `n & ((1 << k) - 1)`
- **Explanation:** Clears all bits from the most significant bit to the `k`th bit.

### **8. Find Position of the Rightmost Set Bit**
- **Formula:** `log2(n & -n) + 1`
- **Explanation:** Use `n & -n` to isolate the rightmost set bit, and then take log base 2 to determine the position.