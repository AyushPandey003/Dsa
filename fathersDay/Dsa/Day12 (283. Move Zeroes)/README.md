## Day 12: Move Zeroes (Problem 283)

## Main Concept

The "Move Zeroes" problem requires us to modify an array in-place such that all zeros are moved to the end of the array, while maintaining the relative order of the non-zero elements. This means if we have `[0, 1, 0, 3, 12]`, the result should be `[1, 3, 12, 0, 0]`, not `[1, 12, 3, 0, 0]` or `[0, 0, 1, 3, 12]`.

The most efficient approach involves a two-pointer technique. One pointer (`lastNonZeroFoundAt` or `insertPos`) keeps track of the position where the next non-zero element should be placed, and the other pointer (`i`) iterates through the array.

## Intuition

Imagine you have two sections in your array:

1.  **Processed Non-Zero Elements:** Elements from the beginning of the array up to `lastNonZeroFoundAt - 1` are all non-zero elements that have been correctly placed.
2.  **Unknown Elements:** Elements from `lastNonZeroFoundAt` to the current iterating pointer `i` are yet to be processed.

The goal is to fill the `Processed Non-Zero Elements` section as we iterate through the `Unknown Elements`.

Here's how the two-pointer approach works:

1.  **Initialization:** Initialize a pointer, say `lastNonZeroFoundAt`, to `0`. This pointer will always point to the next available position for a non-zero element.

2.  **First Pass (Placing Non-Zeros):**
    -   Iterate through the array with a second pointer, `i`, from the beginning to the end.
    -   If `nums[i]` is a non-zero element:
        -   Place `nums[i]` at `nums[lastNonZeroFoundAt]`.
        -   Increment `lastNonZeroFoundAt`.
    -   After this pass, all non-zero elements will be at the beginning of the array, in their original relative order. The elements from `lastNonZeroFoundAt` to the end of the array will contain a mix of zeros and potentially some non-zero elements that were overwritten (but their values were already moved).

3.  **Second Pass (Filling with Zeros):**
    -   After the first pass, all positions from `lastNonZeroFoundAt` to the end of the array should be filled with zeros.
    -   Iterate from `lastNonZeroFoundAt` to the end of the array and set each element to `0`.

## Pro Tips and Tricks

*   **In-place Modification:** The problem explicitly asks for an in-place solution, meaning you should not create a new array. The two-pointer approach achieves this with O(1) extra space.

*   **Maintaining Relative Order:** The key to maintaining relative order is that non-zero elements are only moved forward into the `lastNonZeroFoundAt` position. They are never swapped with elements that are already correctly placed.

*   **Optimization (Single Pass - Swap Method):** A slightly more optimized version can be done in a single pass by swapping. If `nums[i]` is non-zero, swap `nums[i]` with `nums[lastNonZeroFoundAt]` and then increment `lastNonZeroFoundAt`. This avoids the second pass of filling zeros, as zeros are naturally moved to the end during the swaps.
    ```python
    class Solution:
        def moveZeroes(self, nums: list[int]) -> None:
            last_non_zero_index = 0
            for i in range(len(nums)):
                if nums[i] != 0:
                    nums[i], nums[last_non_zero_index] = nums[last_non_zero_index], nums[i]
                    last_non_zero_index += 1
    ```
    While this is a single pass, it might involve more write operations (swaps) than the two-pass approach if there are many zeros at the beginning. Both are O(N) time complexity.

*   **Edge Cases:**
    *   An empty array.
    *   An array with no zeros.
    *   An array with all zeros.
    *   An array with a single element.

*   **Clarity vs. Conciseness:** The two-pass approach (first move non-zeros, then fill zeros) is often easier to understand initially. The single-pass swap method is more concise and can be slightly more efficient in terms of total operations in some cases.