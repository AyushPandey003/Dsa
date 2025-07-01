# Sum of Square Numbers

## Intuition
The problem asks us to determine if a given non-negative integer `c` can be expressed as the sum of squares of two integers, i.e., `a^2 + b^2 = c`. A straightforward approach would be to iterate through all possible values of `a` from 0 up to `sqrt(c)`. For each `a`, we would then check if `c - a^2` is a perfect square. This approach has a time complexity involving `sqrt(c)` iterations and a perfect square check within each iteration.

A more efficient approach utilizes the two-pointer technique. We can initialize one pointer, `left`, to 0 and another pointer, `right`, to `sqrt(c)`. We then calculate the sum of squares `left*left + right*right`. If this sum equals `c`, we have found a solution and can return `true`. If the `current_sum` is less than `c`, it means we need a larger sum, so we increment `left` to increase `left*left`. If `current_sum` is greater than `c`, we need a smaller sum, so we decrement `right` to decrease `right*right`. This process continues as long as `left` is less than or equal to `right`.

## Pro Tip and Trick
The two-pointer approach is highly effective here. The crucial part is correctly setting the initial bounds for `left` and `right`. `left` should start at 0, representing the smallest possible non-negative integer. `right` should start at `sqrt(c)`, as `b` cannot be greater than `sqrt(c)` if `a^2 + b^2 = c` and `a` is non-negative. It's also vital to use `long` or `long long` for `left`, `right`, and `current_sum` to prevent integer overflow, especially when `c` is a large number, as `left * left` or `right * right` could exceed the maximum value of an `int`.

## Main Concept
The core concept behind this solution is the two-pointer technique applied to a search space that exhibits monotonicity. Although we are not directly searching in a sorted array, the values of `a^2` and `b^2` change monotonically as `a` increases and `b` decreases, respectively. This property allows us to efficiently narrow down the search space. By adjusting `left` and `right` based on whether `current_sum` is less than, equal to, or greater than `c`, we systematically explore potential pairs `(a, b)` without needing to check every single combination, leading to an optimized solution.
