# Prime Number of Set Bits in Binary Representation

## Intuition

The problem requires us to count the numbers in a given range `[left, right]` that have a prime number of set bits in their binary representation. The approach is to iterate through each number in the range, count its set bits, and then check if the count is a prime number.

## Pro-tip

For counting set bits, instead of converting the number to a binary string and counting '1's, a more efficient method is to use the Brian Kernighan's algorithm, which is `n &= (n - 1)`.

## Trick

Since the maximum value of `right` is 10^6, the maximum number of set bits will be for a number like `2^20 - 1`, which is less than 20. We can pre-compute or hardcode the prime numbers up to 20 (2, 3, 5, 7, 11, 13, 17, 19) to make the primality test faster.

## Main Concept

This problem combines bit manipulation (counting set bits) and number theory (checking for prime numbers).
