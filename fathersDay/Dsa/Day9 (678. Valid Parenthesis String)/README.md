# Day 9: Valid Parenthesis String (LeetCode 678)

## Main Concept

The problem asks us to determine if a string containing '(', ')', and '*' is valid. The '*' character can be treated as a single '(', a single ')', or an empty string.

The core idea behind the solution is to use a two-pass greedy approach to check for validity:

1.  **Left-to-Right Pass (Checking for sufficient opening parentheses):**
    *   Iterate through the string from left to right.
    *   Maintain a `left_balance` counter.
    *   If the current character is '(' or '*', increment `left_balance`. This is because both can potentially act as an opening parenthesis.
    *   If the current character is ')', decrement `left_balance`.
    *   If `left_balance` ever drops below zero during this pass, it means we have encountered more closing parentheses than available opening parentheses (even when treating '*' as '('). In this case, the string is invalid.

2.  **Right-to-Left Pass (Checking for sufficient closing parentheses):**
    *   Iterate through the string from right to left.
    *   Maintain a `right_balance` counter.
    *   If the current character is ')' or '*', increment `right_balance`. This is because both can potentially act as a closing parenthesis.
    *   If the current character is '(', decrement `right_balance`.
    *   If `right_balance` ever drops below zero during this pass, it means we have encountered more opening parentheses than available closing parentheses (even when treating '*' as ')'). In this case, the string is invalid.

If both passes complete without the respective balance counters dropping below zero, the string is considered valid.

## Intuition

The two passes cover both necessary conditions for a valid parenthesis string:

*   The left-to-right pass ensures that for any prefix of the string, the number of closing parentheses does not exceed the number of opening parentheses (including '*' as potential opening ones). This handles cases like `())`.
*   The right-to-left pass ensures that for any suffix of the string, the number of opening parentheses does not exceed the number of closing parentheses (including '*' as potential closing ones). This handles cases like `(((`.

By checking both directions, we effectively account for the flexible nature of the '*' character.

## Pro Tip and Trick

*   **Greedy Approach:** The solution leverages a greedy strategy. In the left-to-right pass, we are "greedy" about using '*' as an opening parenthesis to satisfy any immediate closing parentheses. In the right-to-left pass, we are "greedy" about using '*' as a closing parenthesis to satisfy any immediate opening parentheses.
*   **Two-Pass Necessity:** A single pass is insufficient because the '*' character's role (as '(', ')', or empty) depends on its context. For example, in `(*))`, a left-to-right pass might treat `*` as `(`, leading to `(())`, which is valid. However, the string is actually invalid because the last `)` has no matching `(`. The right-to-left pass would catch this.
*   **Balance Counters:** The use of simple integer counters for balance is efficient and avoids complex data structures like stacks, which are often used for standard parenthesis problems.
