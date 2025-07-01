# Rotate Image

## Intuition

To rotate an image (represented by an `n x n` 2D matrix) by 90 degrees clockwise, we can observe that the elements move in a specific pattern. A common and efficient approach involves two steps:
1.  **Transpose the matrix:** Swap `matrix[i][j]` with `matrix[j][i]` for all `i < j`.
2.  **Reverse each row:** After transposing, reverse the elements in each row.

## Pro-tip

Transposing the matrix effectively swaps elements across the main diagonal. Reversing each row then completes the 90-degree clockwise rotation. This two-step process is an in-place solution, meaning it doesn't require extra space proportional to the input size.

## Trick

For the transpose step, iterate `i` from `0` to `n-1` and `j` from `i` to `n-1`. This ensures that each pair `(i, j)` and `(j, i)` is swapped only once. For reversing each row, you can use a two-pointer approach (one from the start, one from the end of the row) or a built-in `reverse` function if available.

## Main Concept

This problem is a classic **Matrix Manipulation** problem. It demonstrates how a complex transformation (rotation) can be broken down into simpler, well-defined operations (transpose and reverse) that can be performed in-place.
