# Minimum Remove to Make Valid Parentheses - LeetCode 1249

## Main Concept: Two-Pass String Traversal

The problem asks us to remove the minimum number of parentheses to make the input string a valid parentheses string. A valid parentheses string is defined by:
1.  An empty string is valid.
2.  `AB` is valid if `A` and `B` are valid.
3.  `(A)` is valid if `A` is valid.

The core idea to solve this efficiently is a two-pass approach:

**First Pass (Left to Right):**
-   Iterate through the string from left to right.
-   Maintain a `balance` counter, initialized to 0.
-   If an opening parenthesis `(` is encountered, increment `balance` and append it to a temporary result string.
-   If a closing parenthesis `)` is encountered:
    -   If `balance` is greater than 0 (meaning there's an unmatched opening parenthesis), decrement `balance` and append `)` to the result string.
    -   If `balance` is 0, it means this `)` is an invalid closing parenthesis (no matching `(`), so we skip it.
-   For any other character, append it to the result string.

After the first pass, all invalid `)` characters are removed. However, there might still be unmatched `(` characters (e.g., `((a)`).

**Second Pass (Right to Left):**
-   Iterate through the temporary result string (from the first pass) from right to left.
-   Maintain a `balance` counter, initialized to 0.
-   If a closing parenthesis `)` is encountered, increment `balance` and append it to a final result string.
-   If an opening parenthesis `(` is encountered:
    -   If `balance` is greater than 0 (meaning there's an unmatched closing parenthesis), decrement `balance` and append `(` to the final result string.
    -   If `balance` is 0, it means this `(` is an invalid opening parenthesis (no matching `)`), so we skip it.
-   For any other character, append it to the final result string.

Finally, reverse the final result string to get the correct order.

## Intuition

Think of it like this: In the first pass, we are trying to match every `)` with an available `(`. If a `)` doesn't have a preceding `(`, it's clearly invalid and must be removed. We build a string that has all valid `)` and potentially some excess `(`.

In the second pass, we are dealing with the excess `(`. We iterate from right to left. If an `(` doesn't have a succeeding `)`, it's invalid and must be removed. By doing this in two passes, we ensure that we remove the minimum number of parentheses to achieve a valid string.

## Pro Tip & Trick

-   **Using a Stack (Alternative):** While the two-pass approach is effective, another common way to solve this is by using a stack. In a single pass, you can push the indices of `(` onto a stack. When you encounter a `)`, if the stack is not empty, pop an index (meaning a match is found). If the stack is empty, mark the current `)` for removal. After the pass, any remaining indices in the stack correspond to unmatched `(` that also need to be removed. Then, build the result string by skipping all marked indices.
-   **StringBuilder/Character Array for Efficiency:** When dealing with string manipulations in languages like Java or C++, using `StringBuilder` or character arrays is generally more efficient than repeatedly concatenating strings, as string concatenation often creates new string objects.
-   **Clarity of Two Passes:** The two-pass approach, while perhaps slightly less concise than a stack-based solution, can be very intuitive to understand and implement, especially for those less familiar with stack applications.
-   **Edge Cases:** Consider empty strings, strings with only non-parenthesis characters, and strings with only one type of parenthesis (e.g., `(((` or `)))`). The two-pass approach handles these naturally.
