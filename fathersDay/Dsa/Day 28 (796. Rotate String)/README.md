# Rotate String

## Intuition

If a string `goal` can be obtained by rotating another string `s`, it means `goal` is a cyclic shift of `s`. For example, if `s = "abcde"`, its rotations are `"bcdea"`, `"cdeab"`, `"deabc"`, and `"eabcd"`.

A key insight is to observe what happens when we concatenate `s` with itself. For `s = "abcde"`, `s + s` becomes `"abcdeabcde"`. Now, if we look for any rotation of `s` within this new string, we will find it. For instance, `"cdeab"` is a substring of `"abcdeabcde"`.

## Pro-tip

The problem can be solved in a single line of code in many languages. The core logic is: check if the lengths are equal, and if so, check if `goal` is a substring of `s + s`.

## Trick

This concatenation trick is a very clever and efficient way to check for string rotations. It avoids manual rotation and comparison, which would be more complex and slower.

## Main Concept

This problem is a neat example of a **String Manipulation** puzzle that has an elegant, non-obvious solution. It highlights how creatively combining strings can simplify complex checks.
