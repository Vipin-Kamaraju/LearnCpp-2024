# Common algorithms used for Bitwise manipulation

Here is a list of some of the most useful bitwise operator tricks, formulas, and solutions that are commonly applied for manipulating bits. These are incredibly handy for competitive programming, coding interviews, and bitwise manipulation tasks.

### 1. Turn Off Rightmost Set Bit
**Formula:** `n & (n - 1)`
- **Explanation:** Clears the rightmost `1` bit in the binary representation of `n`.
- **Example:**
  - If `n = 12` (binary `1100`), then `n & (n - 1)` gives `8` (binary `1000`).

### 2. Isolate Rightmost Set Bit
**Formula:** `n & (-n)`
- **Explanation:** Isolates the rightmost `1` bit in `n`. This works because `-n` is the two's complement of `n`, and it flips all bits up to and including the rightmost `1`.
- **Example:**
  - If `n = 10` (binary `1010`), then `n & (-n)` gives `2` (binary `0010`).

### 3. Set Rightmost Zero Bit
**Formula:** `n | (n + 1)`
- **Explanation:** Sets the rightmost `0` bit of `n` to `1`.
- **Example:**
  - If `n = 10` (binary `1010`), then `n | (n + 1)` gives `11` (binary `1011`).

### 4. Turn Off All Bits After the Rightmost Set Bit
**Formula:** `n & (n - 1) + 1`
- **Explanation:** Clears all bits to the right of the rightmost `1` bit.
- **Example:**
  - If `n = 18` (binary `10010`), then `n & (n - 1) + 1` gives `16` (binary `10000`).

### 5. Check if a Number is a Power of 2
**Formula:** `(n & (n - 1)) == 0`
- **Explanation:** A number is a power of `2` if it has only one bit set, which means that `n & (n - 1)` will be `0`.
- **Example:**
  - If `n = 8` (binary `1000`), then `(n & (n - 1)) == 0` is `True`.

### 6. Count the Number of Set Bits (Brian Kernighan’s Algorithm)
**Loop Formula:** `while (n != 0) { n = n & (n - 1); count++; }`
- **Explanation:** Repeatedly turns off the rightmost set bit until `n` becomes `0`, incrementing the count each time.
- This is also and extension of the first algorithm
- **Example:**
  - If `n = 13` (binary `1101`), the number of set bits is `3`.
  
**Alternate Solution**
``` cpp
    while (a != 0) {
        if (a & 1) {
            count++;  // Increment count if the least significant bit is 1
        }
        a = a >> 1;  // Right shift by 1 to move to the next bit
    }
```

### 7. Get the Value with Only the Rightmost Set Bit
**Formula:** `n & ~(n - 1)`
- **Explanation:** Extracts the value of the rightmost set bit.
- **Example:**
  - If `n = 10` (binary `1010`), then `n & ~(n - 1)` gives `2` (binary `0010`).

### 8. Invert All Bits After the Rightmost Set Bit
**Formula:** `n ^ (n + 1)`
- **Explanation:** Flips all bits to the right of the rightmost `0`.
- **Example:**
  - If `n = 12` (binary `1100`), then `n ^ (n + 1)` gives `3` (binary `0011`).

### 9. Check if `n` Has Alternate 1s and 0s
**Formula:** `(n & (n >> 1)) == 0`
- **Explanation:** Checks if a number has alternating bits (like `101010...`).
- **Example:**
  - If `n = 5` (binary `101`), the formula is `True`.

### 10. Toggle (Invert) All Bits
**Formula:** `~n`
- **Explanation:** Inverts all bits in `n`.
- **Example:**
  - If `n = 5` (binary `0000...0101`), `~n` gives `...11111010`.

### 11. Get `n` with Only the Lowest Set Bit Retained
**Formula:** `n & -n`
- **Explanation:** Clears all bits except the lowest set bit.
- **Example:**
  - If `n = 18` (binary `10010`), then `n & -n` results in `2` (binary `00010`).

### 12. Detect if the Bit at Position `k` is Set
**Formula:** `(n & (1 << (k - 1))) != 0`
- **Explanation:** Checks whether the bit at position `k` (1-indexed) is set.
- **Example:**
  - If `n = 13` (binary `1101`) and `k = 3`, `(n & (1 << (3 - 1))) != 0` is `True`.

### 13. Set the Bit at Position `k`
**Formula:** `n | (1 << (k - 1))`
- **Explanation:** Sets the bit at position `k` to `1`.
- **Example:**
  - If `n = 9` (binary `1001`) and `k = 2`, then `n | (1 << (2 - 1))` gives `11` (binary `1011`).

### 14. Clear the Bit at Position `k`
**Formula:** `n & ~(1 << (k - 1))`
- **Explanation:** Clears (sets to `0`) the bit at position `k`.
- **Example:**
  - If `n = 15` (binary `1111`) and `k = 2`, then `n & ~(1 << (2 - 1))` gives `13` (binary `1101`).

### 15. Toggle the Bit at Position `k`
**Formula:** `n ^ (1 << (k - 1))`
- **Explanation:** Toggles (flips) the bit at position `k`.
- **Example:**
  - If `n = 9` (binary `1001`) and `k = 3`, then `n ^ (1 << (3 - 1))` gives `13` (binary `1101`).

---

## More formulas

Absolutely! Here’s an extensive list of bitwise operations and their common usage patterns, formulas, and properties that you might encounter in technical interviews or might be helpful in general programming. I will include a wide variety of problems like checking if a number is odd or even, swapping numbers, checking properties, etc.

### **1. Check if a Number is Odd or Even**
- **Formula:** `n & 1`
  - If `(n & 1) == 0`, then the number is **even**.
  - If `(n & 1) == 1`, then the number is **odd**.
- **Explanation:** The least significant bit (`1`) of a binary number tells if the number is odd or even.

### **2. Swap Two Numbers Without Temporary Variable**
- **Formula Using XOR:**
  ```cpp
  a = a ^ b;
  b = a ^ b;  // b becomes a
  a = a ^ b;  // a becomes b
  ```
- **Explanation:** Using XOR to swap values without needing extra storage.

### **3. Clear (Turn Off) Rightmost Set Bit**
- **Formula:** `n & (n - 1)`
- **Explanation:** Turns off the rightmost `1` in the binary representation of `n`.

### **4. Isolate Rightmost Set Bit**
- **Formula:** `n & (-n)`
- **Explanation:** Isolates the rightmost set bit of `n`. This works because `-n` is the two's complement representation of `n`.

### **5. Set Rightmost Zero Bit**
- **Formula:** `n | (n + 1)`
- **Explanation:** Sets the rightmost `0` bit to `1`.

### **6. Turn Off All Bits After the Rightmost Set Bit**
- **Formula:** `n & (n - 1) + 1`
- **Explanation:** Clears all bits to the right of the rightmost `1` bit, leaving only that bit.

### **7. Check if a Number is a Power of 2**
- **Formula:** `(n & (n - 1)) == 0 && n != 0`
- **Explanation:** A number `n` is a power of 2 if it has only one set bit. `(n & (n - 1))` will be `0` if only one bit is set.

### **8. Count the Number of Set Bits (Brian Kernighan’s Algorithm)**
- **Loop Formula:** 
  ```cpp
  while (n != 0) {
    n = n & (n - 1);
    count++;
  }
  ```
- **Explanation:** Repeatedly turns off the rightmost set bit until `n` becomes `0`, counting the number of times.

### **9. Get Value with Only the Rightmost Set Bit Retained**
- **Formula:** `n & ~(n - 1)`
- **Explanation:** Isolates only the rightmost set bit.

### **10. Invert All Bits After the Rightmost Set Bit**
- **Formula:** `n ^ (n + 1)`
- **Explanation:** Flips all bits after the rightmost set bit.

### **11. Check if Bits are Alternating (Like 101010...)**
- **Formula:** `((n & (n >> 1)) == 0) && n != 0`
- **Explanation:** This checks if the binary representation of `n` has alternating bits.

### **12. Toggle (Invert) All Bits**
- **Formula:** `~n`
- **Explanation:** Inverts every bit in `n`.

### **13. Turn Off `k`th Bit**
- **Formula:** `n & ~(1 << (k - 1))`
- **Explanation:** Turns off the `k`th bit (1-indexed).

### **14. Set the `k`th Bit**
- **Formula:** `n | (1 << (k - 1))`
- **Explanation:** Sets the `k`th bit to `1`.

### **15. Toggle the `k`th Bit**
- **Formula:** `n ^ (1 << (k - 1))`
- **Explanation:** Flips the value of the `k`th bit.

### **16. Check if `k`th Bit is Set**
- **Formula:** `(n & (1 << (k - 1))) != 0`
- **Explanation:** Checks whether the `k`th bit is set.

### **17. Multiply a Number by Power of 2**
- **Formula:** `n << k` 
  - Where `k` is the power.
- **Explanation:** Left-shifting `n` by `k` is equivalent to multiplying `n` by `2^k`.

### **18. Divide a Number by Power of 2**
- **Formula:** `n >> k` 
  - Where `k` is the power.
- **Explanation:** Right-shifting `n` by `k` is equivalent to dividing `n` by `2^k`.

### **19. Clear All Bits from the Least Significant Bit to `k`th Bit (inclusive)**
- **Formula:** `n & ~((1 << k) - 1)`
- **Explanation:** Clears all bits from the least significant bit to the `k`th bit.

### **20. Clear All Bits from the Most Significant Bit to `k`th Bit**
- **Formula:** `n & ((1 << k) - 1)`
- **Explanation:** Clears all bits from the most significant bit to the `k`th bit.

### **21. Find Position of the Rightmost Set Bit**
- **Formula:** `log2(n & -n) + 1`
- **Explanation:** Use `n & -n` to isolate the rightmost set bit, and then take log base 2 to determine the position.

### **22. Find Position of the Leftmost Set Bit**
- **Approach:** Repeatedly right shift the number until it becomes `0` and count the number of shifts.
  ```cpp
  int position = 0;
  while (n > 0) {
    n = n >> 1;
    position++;
  }
  ```

### **23. Reverse the Bits in an Integer**
- **Approach:**
  ```cpp
  unsigned int reverse_bits(unsigned int n) {
      unsigned int result = 0;
      for (int i = 0; i < 32; i++) {
          result <<= 1;
          result |= (n & 1);
          n >>= 1;
      }
      return result;
  }
  ```
- **Explanation:** Iterates through each bit of `n` and constructs the reversed value.

### **24. Find XOR of All Numbers from `1` to `n`**
- **Formula:**
  ```cpp
  int xor_upto_n(int n) {
      if (n % 4 == 0) return n;
      if (n % 4 == 1) return 1;
      if (n % 4 == 2) return n + 1;
      return 0;
  }
  ```
- **Explanation:** Uses the pattern of XOR results to calculate the XOR of all numbers from `1` to `n` in constant time.

### **25. Swap Even and Odd Bits**
- **Formula:**
  ```cpp
  unsigned int swap_even_odd_bits(unsigned int n) {
      unsigned int even_bits = n & 0xAAAAAAAA; // Get all even bits
      unsigned int odd_bits = n & 0x55555555;  // Get all odd bits
      even_bits >>= 1;                         // Shift even bits right
      odd_bits <<= 1;                          // Shift odd bits left
      return (even_bits | odd_bits);
  }
  ```
- **Explanation:** Separates even and odd bits, shifts them appropriately, and recombines them.

### **26. Add Two Numbers Without Using Arithmetic Operators (`+` or `-`)**
- **Formula Using Bitwise Operators:**
  ```cpp
  int add(int a, int b) {
      while (b != 0) {
          unsigned carry = a & b;  // Find carry bits
          a = a ^ b;               // Sum bits where at least one of the bits is not set
          b = carry << 1;          // Carry shifted left
      }
      return a;
  }
  ```
- **Explanation:** Uses XOR for addition and AND plus left-shift to handle carries.

---

Sure! Let's break down what it means to "turn off all bits after the rightmost set bit" and how the formula works.

### **Objective:**
The goal here is to **turn off all bits to the right of the rightmost set bit** (including the rightmost set bit itself). However, I need to make a correction: 

The original formula provided seems incorrect. The correct formula to **turn off all bits after the rightmost set bit** should be:

### **Corrected Formula:**
`n & (n - 1)`

This operation **turns off the rightmost set bit**.

### **Explanation with Examples:**

- Let's consider how `n & (n - 1)` works to achieve the goal of clearing the rightmost set bit and all bits after it.

#### Step-by-Step Explanation:

1. **Take `n` in Binary Form**:
   Let's say `n = 26`. The binary representation of `n` is:

   ```
   n = 26 (in decimal) = 11010 (in binary)
   ```

2. **Subtract 1 from `n`**:
   When we subtract `1` from `n`, we end up changing the rightmost set bit to `0` and flipping all the bits to the right of it.

   ```
   n - 1 = 25 (in decimal) = 11001 (in binary)
   ```

3. **Perform Bitwise AND (`&`) Between `n` and (`n - 1`)**:
   Now, we perform `n & (n - 1)`:

   ```
   n =     11010
   n - 1 = 11001
   --------------
   Result = 11000  (in binary) = 24 (in decimal)
   ```

   In this result:
   - The rightmost set bit of `n` has been cleared.
   - All bits to the right of the rightmost set bit are also cleared.

#### **Another Example:**

Consider `n = 14`, whose binary representation is:

```
n = 14 (in decimal) = 1110 (in binary)
```

1. **Subtract `1` from `n`**:

```
n - 1 = 13 (in decimal) = 1101 (in binary)
```

2. **Perform `n & (n - 1)`**:

```
n =     1110
n - 1 = 1101
-------------
Result = 1100 (in binary) = 12 (in decimal)
```

#### **Why Does It Work?**
- The operation `n - 1` affects only the rightmost set bit and all bits to the right of it.
- When you perform a bitwise AND (`n & (n - 1)`), you are effectively turning **off the rightmost set bit** of `n`.

- After this operation, **all bits to the right of the rightmost set bit**, including the rightmost set bit itself, **are cleared**.

### **Visual Example:**

Let’s break down `n` and `n - 1` more clearly with an example of `n = 26`:

- `n = 11010`
- `n - 1 = 11001`

If you align these:

```
n      = 11010
n - 1  = 11001
---------------
n & (n-1) = 11000
```

- The rightmost `1` bit of `n` has been turned off in the result (`11000`), and all bits to the right of it are also cleared.

### **Summary of Formula**:
- **`n & (n - 1)`** effectively **clears the rightmost set bit**.
- This operation is useful in a variety of bit manipulation problems, such as counting the number of set bits, isolating bits, or doing efficient power-of-two checks.

### **Applications**:
1. **Counting Set Bits**:
   You can use this trick to count the number of set bits in an integer. Repeatedly turning off the rightmost set bit and counting the iterations will give you the total number of set bits.

2. **Checking Powers of Two**:
   You can check if a number is a power of two by verifying if it has only one set bit. If `n & (n - 1)` results in `0`, then `n` is a power of two.

### **Incorrect Original Explanation**:
The original explanation I provided mistakenly claimed that the formula was `n & (n - 1) + 1` to clear bits after the rightmost set bit, but this was incorrect. The correct formula is `n & (n - 1)` to **turn off the rightmost set bit**.

