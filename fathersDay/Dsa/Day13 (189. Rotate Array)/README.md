## Day 13: Rotate Array (Problem 189)

## Main Concept

The "Rotate Array" problem asks us to rotate an array to the right by `k` steps. This means the last `k` elements will move to the beginning, and the remaining elements will shift accordingly. A highly efficient and in-place method to achieve this is the **three-reversal algorithm**.

The core idea is based on the observation that rotating an array `[1, 2, 3, 4, 5, 6, 7]` by `k=3` steps to the right results in `[5, 6, 7, 1, 2, 3, 4]`. This can be achieved by:

1.  **Reversing the entire array:** `[7, 6, 5, 4, 3, 2, 1]`
2.  **Reversing the first `k` elements:** `[5, 6, 7, 4, 3, 2, 1]` (for `k=3`, reverse `[7, 6, 5]` to `[5, 6, 7]`)
3.  **Reversing the remaining `n-k` elements:** `[5, 6, 7, 1, 2, 3, 4]` (reverse `[4, 3, 2, 1]` to `[1, 2, 3, 4]`)

## Intuition

Imagine the array `nums` is split into two parts: the last `k` elements (which will become the prefix after rotation) and the first `n-k` elements (which will become the suffix). Let's call these `A` and `B` respectively.

Original: `[A B]`
Desired: `[B A]` (where `B` is the last `k` elements and `A` is the first `n-k` elements)

1.  **Reverse the entire array:** This transforms `[A B]` into `[B^R A^R]`, where `X^R` denotes the reversed version of `X`. For example, `[1,2,3,4,5,6,7]` becomes `[7,6,5,4,3,2,1]`. Here, `A = [1,2,3,4]` and `B = [5,6,7]`. After reversing the whole array, we get `[7,6,5,4,3,2,1]`, which is `[B^R A^R]`.

2.  **Reverse the first `k` elements:** This reverses `B^R` back to `B`. So, `[B^R A^R]` becomes `[B A^R]`. In our example, `[7,6,5,4,3,2,1]` with `k=3`, we reverse `[7,6,5]` to `[5,6,7]`, resulting in `[5,6,7,4,3,2,1]`.

3.  **Reverse the remaining `n-k` elements:** This reverses `A^R` back to `A`. So, `[B A^R]` becomes `[B A]`, which is our desired rotated array. In our example, we reverse `[4,3,2,1]` to `[1,2,3,4]`, finally getting `[5,6,7,1,2,3,4]`.

This method works because reversing a reversed segment restores its original order, and by strategically reversing the whole array and then its two parts, we effectively achieve the rotation.

## Pro Tips and Tricks

*   **Handle `k` greater than `n`:** The rotation amount `k` can be larger than the array's length `n`. In such cases, `k % n` gives the effective number of rotations. For example, rotating by `n` steps is the same as rotating by `0` steps. Always calculate `k = k % n` at the beginning.

*   **In-place Modification:** The three-reversal method is excellent because it modifies the array in-place, requiring only O(1) extra space (excluding the input array itself).

*   **Edge Case `k = 0`:** If `k` becomes `0` after the modulo operation, no rotation is needed, and you can return early.

*   **Understanding `std::reverse` (C++) / `Collections.reverse` (Java) / `list.reverse()` (Python):** These functions typically reverse a contiguous range or the entire list. For the three-reversal method, you'll need to apply them to specific sub-arrays or slices.

*   **Alternative Methods (for context, but three-reversal is preferred):**
    *   **Using an extra array:** Create a new array, place elements at their rotated positions, then copy back. This is O(N) space and O(N) time.
    *   **Cyclic Replacements:** For each element, move it to its correct rotated position, and continue this cycle until all elements are placed. This is O(1) space but can be more complex to implement correctly and might involve multiple passes or tracking visited elements. The three-reversal method is generally simpler to implement and understand for its efficiency.