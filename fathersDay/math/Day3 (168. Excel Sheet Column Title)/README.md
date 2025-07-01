# Excel Sheet Column Title

## Intuition
This problem asks us to convert a given positive integer into its corresponding Excel column title. The mapping is similar to a base-26 system, but with a crucial difference: there is no 'zero' equivalent. Instead of 0-25, the system uses 1-26, where 'A' corresponds to 1, 'B' to 2, ..., 'Z' to 26. This means that when we perform modulo operations, we need to adjust the input number to be 0-indexed before taking the modulo, and then convert back to 1-indexed for the character.

For example, if we have `n = 26`, the remainder `26 % 26` would be 0, which would map to 'A' if we directly used `A + 0`. However, 26 should map to 'Z'. This implies that we should treat 26 as the '0th' character in a 0-indexed system, and then map it to 'Z'. This is achieved by decrementing `n` by 1 before taking the modulo. So, for `n = 26`, we use `n-1 = 25`. Then `25 % 26 = 25`, which maps to 'Z'. The quotient `25 // 26 = 0`, which correctly terminates the loop.

Consider `n = 27`. Decrementing `n` gives `26`. `26 % 26 = 0`, which maps to 'A'. The quotient `26 // 26 = 1`. Now `n` becomes 1. Decrementing `n` gives `0`. `0 % 26 = 0`, which maps to 'A'. The quotient `0 // 26 = 0`. The loop terminates. Reversing the characters gives "AA". This is correct.

## Pro Tip and Trick
The key trick is to adjust the input `n` by subtracting 1 (`n--` or `n = n - 1`) at the beginning of each iteration. This effectively converts the 1-indexed system (1-26) to a 0-indexed system (0-25), making the modulo and division operations behave as expected for a base-26 conversion. After getting the remainder, you add `ord('A')` to it to get the ASCII value of the corresponding character.

## Main Concept
The core concept is a base conversion from base-10 to base-26, but with a slight modification due to the 1-indexed nature of Excel column titles. Each character represents a 'digit' in base 26. We extract the rightmost 'digit' (character) by taking the modulo 26, and then update the number by dividing by 26. This process is repeated until the number becomes zero. Since we are extracting digits from right to left, the resulting characters need to be reversed to form the final column title.
