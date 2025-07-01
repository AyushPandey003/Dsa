# Number of Subarrays With LCM Equal to K

## Problem Description
Given an array of integers `nums` and an integer `k`, return the number of subarrays of `nums` such that the least common multiple (LCM) of the subarray elements is equal to `k`.

## Main Concepts

This problem revolves around the concept of Least Common Multiple (LCM) and Greatest Common Divisor (GCD).

1.  **Least Common Multiple (LCM):** The smallest positive integer that is divisible by both `a` and `b`. The relationship between LCM and GCD is given by the formula:
    `LCM(a, b) = (a * b) / GCD(a, b)`

2.  **Greatest Common Divisor (GCD):** The largest positive integer that divides two or more integers without leaving a remainder.

3.  **Subarrays:** Contiguous parts of an array. For an array of size `N`, there are `N * (N + 1) / 2` possible subarrays.

## Intuition (Brute-Force Approach)

The most straightforward approach is to iterate through all possible subarrays, calculate their LCM, and check if it equals `k`.

1.  **Outer Loop (Starting Point `i`):** Iterate from the first element to the last, considering each element as the potential start of a subarray.

2.  **Inner Loop (Ending Point `j`):** For each starting point `i`, iterate from `i` to the end of the array, extending the current subarray.

3.  **LCM Calculation:** Maintain a `current_lcm` for the subarray `nums[i...j]`. When extending the subarray from `nums[i...j-1]` to `nums[i...j]`, the new `current_lcm` is `LCM(current_lcm_of_nums[i...j-1], nums[j])`.

4.  **Check and Count:**
    *   If `current_lcm == k`, increment the count of valid subarrays.
    *   If `current_lcm > k`, then any further extension of this subarray (by adding more elements) will only result in an LCM that is greater than or equal to `current_lcm`. Since we are looking for an LCM *equal* to `k`, and the LCM can only increase or stay the same when adding positive integers, we can `break` the inner loop and move to the next starting point `i`. This is a crucial optimization.
    *   If `current_lcm < k`, continue to the next element in the inner loop.

## Pro Tips and Tricks

*   **LCM and GCD Implementation:** Ensure you have correct implementations for GCD and LCM. Most languages have built-in GCD functions (e.g., `math.gcd` in Python, `std::gcd` in C++17, or you can implement Euclidean algorithm for Java).
*   **Preventing Overflow:** When calculating LCM using `(a * b) / GCD(a, b)`, be mindful of potential integer overflow if `a * b` exceeds the maximum value of the integer type. Use `long long` in C++ or `long` in Java for `current_lcm` and intermediate calculations to prevent this. The formula `(a / GCD(a, b)) * b` is generally safer as it performs division first.
*   **Optimization (Early Exit):** The `if (current_lcm > k) break;` condition is vital for performance. Since LCMs of positive integers are non-decreasing as you add more elements to a subarray, if the LCM ever exceeds `k`, it will never become `k` again for that starting `i`.
*   **Edge Cases:**
    *   `k = 0`: The problem constraints usually specify positive integers, but if `k` could be 0, the LCM of any positive integers is never 0. So, if `k=0`, the count should be 0.
    *   `nums[i] > k`: If an individual number `nums[i]` is greater than `k`, any subarray containing `nums[i]` will have an LCM of at least `nums[i]`, which means it will be greater than `k`. So, if `nums[i] > k`, you can `continue` to the next `i` for the outer loop.

## Time and Space Complexity

*   **Time Complexity:** O(N^2 * log(max_val)), where N is the length of `nums` and `max_val` is the maximum value in `nums`. The `N^2` comes from the nested loops, and `log(max_val)` comes from the GCD calculation.
*   **Space Complexity:** O(1) (excluding the input array), as we only use a few variables for calculation.

## Example

Let `nums = [3, 6, 2, 7, 1]` and `k = 6`.

| i | j | Subarray | current_lcm | Check `current_lcm == k` | Count |
|---|---|----------|-------------|--------------------------|-------|
| 0 | 0 | `[3]`    | 3           | No                       | 0     |
|   | 1 | `[3, 6]` | LCM(3,6)=6  | Yes                      | 1     |
|   | 2 | `[3, 6, 2]` | LCM(6,2)=6  | Yes                      | 2     |
|   | 3 | `[3, 6, 2, 7]` | LCM(6,7)=42 | No (42 > 6, break)       | 2     |
| 1 | 1 | `[6]`    | 6           | Yes                      | 3     |
|   | 2 | `[6, 2]` | LCM(6,2)=6  | Yes                      | 4     |
|   | 3 | `[6, 2, 7]` | LCM(6,7)=42 | No (42 > 6, break)       | 4     |
| 2 | 2 | `[2]`    | 2           | No                       | 4     |
|   | 3 | `[2, 7]` | LCM(2,7)=14 | No (14 > 6, break)       | 4     |
| 3 | 3 | `[7]`    | 7           | No (7 > 6, continue)     | 4     |
| 4 | 4 | `[1]`    | 1           | No                       | 4     |

Final Count: 4
