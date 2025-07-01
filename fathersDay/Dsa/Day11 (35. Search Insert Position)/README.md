# Search Insert Position - LeetCode 35

## Main Concept: Binary Search

The problem asks us to find the index of a `target` value in a sorted array `nums`. If the `target` is found, return its index. If not, return the index where it would be if it were inserted in order.

The core concept to solve this problem efficiently is **Binary Search**. Binary search is an algorithm that finds the position of a target value within a sorted array. It works by repeatedly dividing the search interval in half. If the value of the search key is less than the item in the middle of the interval, narrow the interval to the lower half. Otherwise, narrow it to the upper half. Repeatedly check until the value is found or the interval is empty.

Here's how it applies to this problem:

1.  **Initialization:** Set `left` to the first index (0) and `right` to the last index (`len(nums) - 1`).
2.  **Iteration:** While `left` is less than or equal to `right`:
    *   Calculate the `mid` index: `mid = left + (right - left) // 2` (this way of calculating `mid` prevents potential integer overflow compared to `(left + right) // 2`).
    *   **Comparison:**
        *   If `nums[mid]` is equal to `target`, we found the target, so return `mid`.
        *   If `nums[mid]` is less than `target`, it means the `target` must be in the right half (or would be inserted after `mid`), so update `left = mid + 1`.
        *   If `nums[mid]` is greater than `target`, it means the `target` must be in the left half (or would be inserted before `mid`), so update `right = mid - 1`.
3.  **Return Value:** When the loop terminates (`left > right`), it means the `target` was not found in the array. At this point, `left` will be the correct index where the `target` should be inserted to maintain the sorted order.

## Intuition

Imagine you're looking for a word in a dictionary. You don't start from the beginning and read every word. Instead, you open to the middle. If the word you're looking for comes before the word on that page, you then look in the first half. If it comes after, you look in the second half. You keep halving the search space until you find the word or realize it's not there. If it's not there, the `left` pointer will naturally land on the spot where it *should* be inserted.

## Pro Tip & Trick

-   **`left + (right - left) / 2` for `mid`:** This is a common optimization to prevent integer overflow when `left` and `right` are very large, although in most competitive programming contexts with typical array sizes, `(left + right) / 2` is usually fine.
-   **Understanding the `left` return:** When the loop `while left <= right` finishes, `left` will always point to the first element that is greater than `target`, or to `nums.length` if `target` is greater than all elements. This is precisely the insertion point.
-   **Time Complexity:** Binary search has a time complexity of **O(log n)**, making it extremely efficient for large sorted arrays. This is significantly better than a linear scan (O(n)).
-   **Pre-sorted Array:** Binary search *requires* the input array to be sorted. If the array is not sorted, you would need to sort it first, which would add an O(n log n) complexity.
