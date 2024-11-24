In C++, **bitwise operators** allow you to perform operations at the bit level of an integer. These operators are very useful for low-level programming, working with flags, and optimizing performance. 

### Bitwise AND (`&`)
### Bitwise OR (`|`)
### Bitwise XOR (`^`)
The **bitwise XOR** operator compares each bit of two operands and returns `1` if the corresponding bits are different. It returns `0` if the corresponding bits are the same.

**Example:**
```cpp
int a = 5;  // 0101 in binary
int b = 3;  // 0011 in binary
int result = a ^ b; // result is 6 (0110 in binary)
```

| Bit of `a` | Bit of `b` | Result (a ^ b) |
|------------|------------|----------------|
| 0          | 0          | 0              |
| 0          | 1          | 1              |
| 1          | 0          | 1              |
| 1          | 1          | 0              |

### Bitwise NOT (`~`)
The **bitwise NOT** operator flips all the bits of the operand, converting `1` to `0` and `0` to `1`. This is also known as the **one's complement** operation.

**Example:**
```cpp
int a = 5;  // 0101 in binary
int result = ~a; // result is -6 (in 32-bit, 11111111111111111111111111111010)
```
- In a 32-bit system, applying `~` to `5` results in `11111111111111111111111111111010`, which is `-6` in signed notation due to two's complement representation.

### Left Shift (`<<`)
The **left shift** operator shifts the bits of the operand to the left by a specified number of positions, adding zeros on the right side. The leftmost bits are discarded.

**Example:**
```cpp
int a = 5;  // 0101 in binary
int result = a << 1; // result is 10 (1010 in binary)
```
- Shifting left by 1 is equivalent to multiplying by 2.

### Right Shift (`>>`)
The **right shift** operator shifts the bits of the operand to the right by a specified number of positions. The behavior of filling bits depends on whether the operand is signed or unsigned.
- **For signed integers**, the sign bit may be filled (arithmetic shift).
- **For unsigned integers**, `0` is always filled (logical shift).

**Example:**
```cpp
int a = 20; // 10100 in binary
int result = a >> 2; // result is 5 (00101 in binary)
```
- Shifting right by 1 is equivalent to dividing by 2 (ignoring remainder).

### Summary Table with All Combinations of Bitwise Operators
Let’s use two 4-bit numbers to illustrate these operations. Consider `a = 5` (`0101` in binary) and `b = 3` (`0011` in binary):

| Operation       | `a`      | `b`      | Result    | Binary Result |
|-----------------|----------|----------|-----------|---------------|
| `a & b`         | `0101`   | `0011`   | `1`       | `0001`        |
| `a | b`         | `0101`   | `0011`   | `7`       | `0111`        |
| `a ^ b`         | `0101`   | `0011`   | `6`       | `0110`        |
| `~a`            | `0101`   | N/A      | `-6`      | `11111010`    |
| `a << 1`        | `0101`   | N/A      | `10`      | `1010`        |
| `a >> 1`        | `0101`   | N/A      | `2`       | `0010`        |

### Important Notes
1. **Use Cases**:
   - **Bitwise AND (`&`)** is commonly used for masking operations (e.g., checking if a particular bit is set).
   - **Bitwise OR (`|`)** is used for setting bits.
   - **Bitwise XOR (`^`)** is used to toggle bits.
   - **Bitwise NOT (`~`)** is used to invert all the bits.
   - **Shift operations (`<<` and `>>`)** are used for bit manipulation, efficient multiplication, or division by powers of 2.

2. **Operator Precedence**:
   - Bitwise operators have lower precedence than arithmetic operators but higher precedence than logical operators.
   - Parentheses are recommended for clarity.

3. **Signed vs. Unsigned Behavior**:
   - For right shift (`>>`) of signed numbers, the result may vary depending on whether it's an arithmetic or logical shift, which is implementation-dependent.

4. **Masking Example**:
   - You can use `&` with a mask to extract specific bits. For example, if you want to check if the least significant bit of `a` is set:
     ```cpp
     int a = 5;  // 0101 in binary
     if (a & 1) {
         // Least significant bit is 1 (odd number)
     }
     ```

5. **Bitwise Swap Using XOR**:
   - A common trick is to swap two numbers without a temporary variable using XOR:
     ```cpp
     int a = 5, b = 3;
     a = a ^ b; // a becomes 6
     b = a ^ b; // b becomes 5
     a = a ^ b; // a becomes 3
     ```

Bitwise operators are powerful tools, particularly for low-level programming tasks, optimizations, and handling data that must be represented as individual bits. They can also be challenging to use correctly, which is why a deep understanding of their behavior is essential for their effective use.