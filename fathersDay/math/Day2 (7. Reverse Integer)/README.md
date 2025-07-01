# 7. Reverse Integer

## Intuition

The problem asks us to reverse the digits of a given 32-bit signed integer. The main challenges are handling negative numbers and detecting integer overflow. If the reversed integer overflows, we should return 0.

My approach involves:
1.  **Handling the Sign:** Determine the sign of the input number first. If it's negative, store the sign and work with its absolute value. This simplifies the digit reversal process.
2.  **Digit Reversal:** Extract digits one by one from the original number using the modulo operator (`% 10`) and build the reversed number by multiplying the current reversed number by 10 and adding the extracted digit.
3.  **Overflow Check:** Since the reversed number can exceed the 32-bit integer limit, it's crucial to check for overflow. This check should ideally happen *during* the reversal process or *after* the reversal using a larger data type (like `long` in Java/C++) to temporarily hold the reversed number before casting it back to `int`.

## Pro Tip and Trick

**Preventing Overflow During Reversal:**

To robustly handle the overflow condition, especially when building the `reversed_x` number, it's best to use a `long` (in Java/C++) or a similar larger integer type for `reversed_x` during the calculation. This prevents intermediate overflows before the final check.

After the reversal is complete, compare the `long` `reversed_x` with `Integer.MAX_VALUE` and `Integer.MIN_VALUE` (or `2^31 - 1` and `-2^31` respectively) to determine if it fits within the 32-bit signed integer range. If it doesn't, return 0.

**Digit Extraction:**
-   `digit = x % 10`: Gets the last digit.
-   `x /= 10` (or `x //= 10` in Python): Removes the last digit from `x`.

## Main Concepts

1.  **Integer Manipulation:** Using modulo (`%`) and integer division (`/`) to extract and remove digits from an integer.
2.  **Sign Handling:** Separating the sign from the number to simplify the reversal logic and applying it back at the end.
3.  **Overflow Detection:** Understanding the limits of integer data types (e.g., 32-bit signed integer range is from -2,147,483,648 to 2,147,483,647). The use of a `long` type for intermediate calculations is a common and effective strategy to prevent premature overflow and allow for a final, accurate check.
4.  **Iterative Approach:** A `while` loop is used to process digits until the original number becomes 0.
