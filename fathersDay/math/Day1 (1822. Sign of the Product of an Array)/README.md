# 1822. Sign of the Product of an Array

## Intuition

The problem asks us to determine the sign of the product of all elements in an integer array. We don't need to calculate the actual product, which could be very large or small and lead to overflow issues. Instead, we only care about its sign: positive (1), negative (-1), or zero (0).

The key observations are:
1.  If any number in the array is `0`, the product of all numbers will be `0`.
2.  If there are an even number of negative numbers, the product will be positive.
3.  If there are an odd number of negative numbers, the product will be negative.
4.  Positive numbers do not change the sign of the product.

Therefore, we can simply iterate through the array and keep track of the sign.

## Pro Tip and Trick

Instead of multiplying numbers, which can lead to integer overflow, maintain a `sign` variable initialized to `1` (representing a positive sign).
- If you encounter a `0`, immediately return `0` because the product will be zero.
- If you encounter a negative number, flip the `sign` by multiplying it by `-1`.
- If you encounter a positive number, do nothing, as it doesn't affect the sign.

This approach efficiently determines the final sign without complex calculations.

## Main Concepts

1.  **Properties of Multiplication with Zero:** Any number multiplied by zero results in zero. This is the highest priority condition.
2.  **Properties of Multiplication with Negative Numbers:**
    *   Multiplying a positive number by a negative number results in a negative number.
    *   Multiplying a negative number by a negative number results in a positive number.
    *   In essence, each negative number encountered flips the current sign of the product.
3.  **Properties of Multiplication with Positive Numbers:** Multiplying by a positive number does not change the sign of the product.
4.  **Sign Tracking:** The core idea is to track the cumulative effect of negative numbers on the product's sign. An initial positive sign (1) is flipped for each negative number.
