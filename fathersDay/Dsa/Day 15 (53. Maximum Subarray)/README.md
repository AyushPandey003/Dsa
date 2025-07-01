# Day 15: Maximum Subarray (LeetCode 53)

## Main Concept

The problem asks us to find the contiguous subarray within a given integer array `nums` (containing at least one number) which has the largest sum, and return its sum.

This is a classic dynamic programming problem that can be solved efficiently using **Kadane's Algorithm**.

Kadane's Algorithm works by iterating through the array and maintaining two variables:
1.  **`current_sum`**: The maximum sum of a subarray ending at the current position.
2.  **`max_sum`**: The overall maximum sum found so far across all subarrays.

At each element `num` in the array:
*   `current_sum` is updated to be the maximum of `num` itself (starting a new subarray from `num`) or `current_sum + num` (extending the previous subarray).
*   `max_sum` is updated to be the maximum of `max_sum` and `current_sum`.

## Intuition

The intuition behind Kadane's Algorithm is that if we are trying to find the maximum sum subarray ending at the current position `i`, there are two possibilities:
1.  The maximum sum subarray ending at `i` is just the element `nums[i]` itself (meaning the previous `current_sum` was negative and dragging down the sum).
2.  The maximum sum subarray ending at `i` is `nums[i]` added to the maximum sum subarray ending at `i-1`.

We choose the larger of these two options for `current_sum`. Simultaneously, we keep track of the overall `max_sum` found anywhere in the array. If `current_sum` ever becomes negative, it means that including previous elements would only decrease the sum, so it's better to start a new subarray from the current element.

## Pro Tip and Trick

*   **Kadane's Algorithm:** This is the standard and most efficient solution for this problem. It's a greedy approach that works in `O(N)` time complexity and `O(1)` space complexity.

*   **Initialization:**
    *   Initialize both `max_sum` and `current_sum` to the first element of the array (`nums[0]`). This handles cases where all numbers are negative (e.g., `[-2, -1, -3]`, the answer should be -1).

*   **Iteration:** Start iterating from the second element (`nums[1]`) onwards.

*   **The `max(num, current_sum + num)` step:** This is the core of Kadane's. It decides whether to extend the current subarray or start a new one. If `current_sum` becomes negative, it's discarded, and a new subarray starts from the current `num`.

*   **The `max(max_sum, current_sum)` step:** This ensures that `max_sum` always holds the largest sum found across *any* subarray encountered so far, not just those ending at the current position.

*   **Contiguous Subarray:** Remember that the subarray must be contiguous. You cannot skip elements.

*   **At Least One Number:** The problem states the subarray must contain at least one number. This is why initializing `max_sum` and `current_sum` with `nums[0]` is important, as it correctly handles arrays with a single element or all negative elements.