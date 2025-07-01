# Greatest Common Divisor of Strings

## Intuition

If a string `t` divides both `str1` and `str2`, then `str1` and `str2` must be formed by repeating `t`. This implies that `str1 + str2` must be equal to `str2 + str1`. If this condition is not met, then no such common divisor string exists.

If the condition holds, the largest string `t` that can divide both `str1` and `str2` must have a length equal to the greatest common divisor (GCD) of the lengths of `str1` and `str2`.

## Pro-tip

The condition `str1 + str2 == str2 + str1` is a clever way to check if two strings are composed of the same repeating substring.

## Trick

Instead of implementing the GCD function yourself, you can use the `math.gcd` function in Python or `std::gcd` in C++.

## Main Concept

This problem combines string manipulation with number theory (specifically, the greatest common divisor).
