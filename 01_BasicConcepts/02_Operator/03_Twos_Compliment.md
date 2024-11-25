====================================================
---
## Two's Compliment
====================================================
---

The notation `-n` is often used to represent the **two's complement** of a number `n` in programming and bitwise operations. Let's break down what this means and why it's used this way.

### **What is Two's Complement?**
- **Two's complement** is a method for representing **negative integers** in binary.
- It is the most common way of representing signed integers in binary in computer systems because it simplifies binary arithmetic operations like addition, subtraction, and allows for easier handling of negative numbers.

To compute the **two's complement** of a number `n`, you:
1. **Invert all the bits** of `n` (take the bitwise NOT).
2. **Add `1`** to the inverted result.

### **Two's Complement of `n` as `-n` in Bitwise Operations**
- When you write `-n` in many programming languages (like C, C++, Java, Python), the language automatically calculates the **two's complement** of `n`.
- Therefore, `-n` in code doesn’t just mean a simple negation; it means finding the **two's complement**, which effectively gives you the negative binary representation of `n`.

### **Example: Calculating Two's Complement**
Let’s go through an example using an 8-bit representation of `n` to see how **two's complement** is calculated and why `-n` represents it.

Consider `n = 5`:

1. **Write `n` in Binary**:
   - In an 8-bit representation, `5` is represented as:
     ```
     0000 0101
     ```

2. **Invert All the Bits**:
   - Flip every bit of `5` (i.e., apply bitwise NOT):
     ```
     1111 1010
     ```

3. **Add `1`**:
   - Add `1` to the result of the inversion:
     ```
     1111 1010 + 1 = 1111 1011
     ```

   - The result is `1111 1011`, which is the **two's complement representation** of `-5`.
