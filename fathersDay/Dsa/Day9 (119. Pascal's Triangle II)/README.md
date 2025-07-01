## Day 9: Pascal's Triangle II (Problem 119)

## Main Concept

The "Pascal's Triangle II" problem asks us to return only the `rowIndex`-th (0-indexed) row of Pascal's Triangle. Pascal's Triangle is a triangular array of the binomial coefficients. The key property of Pascal's Triangle is that each number is the sum of the two numbers directly above it.

For example, the first few rows are:

```
Row 0:      [1]
Row 1:     [1, 1]
Row 2:    [1, 2, 1]
Row 3:   [1, 3, 3, 1]
Row 4:  [1, 4, 6, 4, 1]
```

## Intuition

To generate the `rowIndex`-th row, we can leverage the property that each element (except the first and last, which are always 1) is the sum of the two elements directly above it from the *previous* row.

### Approach 1: Building Row by Row (as in Pascal's Triangle I)

One straightforward way is to generate the triangle row by row up to `rowIndex`. This is similar to how Pascal's Triangle I is solved:

1.  Initialize a list of lists (or vector of vectors) to store the triangle.
2.  For each row `i` from `0` to `rowIndex`:
    *   Create a new row list of size `i + 1`.
    *   Set the first and last elements of the current row to `1`.
    *   For elements in between (`j` from `1` to `i-1`), calculate `current_row[j] = previous_row[j-1] + previous_row[j]`.
    *   Add the current row to the triangle.
3.  Finally, return the `rowIndex`-th row from the stored triangle.

This approach is simple to understand and implement, but it stores the entire triangle up to `rowIndex`, which might not be memory-efficient if `rowIndex` is very large.

### Approach 2: Optimized Space (Generating In-Place or with O(k) space)

Since we only need the `rowIndex`-th row, we can optimize space. Notice that to calculate the current row, we only need the values from the *previous* row. We can maintain a single list representing the current row being built.

1.  Initialize a list `row` with `[1]` for `rowIndex = 0`.
2.  For each subsequent row up to `rowIndex`:
    *   Start from the end of the current `row` list (excluding the last element, which will become the new `1`).
    *   Update `row[j] = row[j] + row[j-1]`.
    *   Append a `1` to the end of the `row` list.

This approach uses O(k) space, where k is the `rowIndex`, as it only stores the current row being computed.

## Pro Tips and Tricks

*   **Base Cases:** Handle `rowIndex = 0` (returns `[1]`) and negative `rowIndex` (returns empty list) explicitly.

*   **Modulo Operator for Large `rowIndex` (Not applicable here):** For problems involving very large `rowIndex` where intermediate values might exceed integer limits, you might need to use modulo arithmetic. However, for this problem's typical constraints, standard integer types are usually sufficient.

*   **Space Optimization:** The most common and efficient solution for this problem is the O(k) space approach. It avoids storing the entire triangle.

*   **Iterating Backwards for In-Place Update:** When updating a single row in-place (Approach 2), it's crucial to iterate from right to left (from `j = i-1` down to `1`). If you iterate from left to right, you would overwrite `row[j]` before `row[j+1]` is used to calculate `row[j+1]`, leading to incorrect results.

    Example for `row = [1, 3, 3, 1]` to `row = [1, 4, 6, 4, 1]`:
    -   `row[3]` (value 1) becomes `row[3] + row[2]` (1+3=4). `row` is now `[1, 3, 3, 4]`
    -   `row[2]` (value 3) becomes `row[2] + row[1]` (3+3=6). `row` is now `[1, 3, 6, 4]`
    -   `row[1]` (value 3) becomes `row[1] + row[0]` (3+1=4). `row` is now `[1, 4, 6, 4]`
    -   Finally, append `1`: `[1, 4, 6, 4, 1]`

*   **Combinatorics (Advanced):** Each element in Pascal's Triangle can also be calculated using binomial coefficients: `C(n, k) = n! / (k! * (n-k)!)`, where `n` is the `rowIndex` and `k` is the element's index within that row. This can be used for a direct calculation of the `rowIndex`-th row without needing previous rows, but it involves calculating factorials, which can lead to large numbers and potential overflow issues if not handled carefully (e.g., by calculating `C(n, k)` iteratively).

    For example, `row[j] = row[j-1] * (rowIndex - j + 1) / j` can be used to calculate elements iteratively from the previous one, starting with `row[0] = 1`.

    ```python
    class Solution:
        def getRow(self, rowIndex: int) -> list[int]:
            row = [1] * (rowIndex + 1)
            for i in range(1, rowIndex + 1):
                row[i] = row[i-1] * (rowIndex - i + 1) // i
            return row
    ```
    This is the most mathematically direct and often the most efficient approach for large `rowIndex` if integer overflow is managed.