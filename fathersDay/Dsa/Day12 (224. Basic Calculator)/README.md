# Day 12: Basic Calculator (Problem 224)

## Main Concept

The "Basic Calculator" problem involves evaluating a string expression that can contain integers, '+', '-', '(', ')', and spaces. The core idea behind solving this problem is to use a stack-based approach to handle the order of operations, particularly the nested expressions within parentheses, and to correctly apply signs.

We process the expression character by character, maintaining a `result` variable for the current sum, a `sign` variable (1 for positive, -1 for negative) for the current number, and a `num` variable to build multi-digit numbers.

## Intuition

1.  **Processing Numbers and Operators:**
    -   When a digit is encountered, we build the `num` by concatenating digits.
    -   When a '+' or '-' is encountered, it signifies the end of the current number. We add `sign * num` to the `result`, reset `num` to 0, and update `sign` based on the operator.

2.  **Handling Parentheses `(`:**
    -   An opening parenthesis `(` indicates the start of a new sub-expression that needs to be evaluated independently. Before starting this sub-expression, the current `result` and the `sign` that applies to this sub-expression (i.e., the sign immediately preceding the `(`) must be saved.
    -   We push the current `result` onto the stack.
    -   We then push the current `sign` onto the stack.
    -   After saving the context, we reset `result` to 0 and `sign` to 1 to begin evaluating the new sub-expression from scratch.

3.  **Handling Parentheses `)`:**
    -   A closing parenthesis `)` signifies the end of a sub-expression. At this point, the `num` (if any) is added to the current `result` of the sub-expression.
    -   Now, we need to incorporate this sub-expression's `result` back into the overall calculation. We pop the `sign` that was active *before* the opening parenthesis from the stack and multiply the sub-expression's `result` by it.
    -   Finally, we pop the `result` that was accumulated *before* the opening parenthesis from the stack and add it to the current `result`.

4.  **Final Calculation:** After iterating through the entire string, any remaining `num` (which would be the last number in the expression) must be added to the `result` with its corresponding `sign`.

## Pro Tips and Tricks

*   **Preprocessing (Remove Spaces):** It's often beneficial to remove all spaces from the input string at the beginning. This simplifies the parsing logic as you don't have to account for spaces during character iteration.

*   **Handling the Last Number:** Always remember to add the `sign * num` to the `result` *after* the main loop finishes. The last number in the expression won't be followed by an operator or parenthesis, so it needs a final processing step.

*   **Stack Order for Parentheses:** When handling a closing parenthesis `)`, ensure you pop the elements from the stack in the correct order: first the `sign` that was active before the `(` (which was pushed last), and then the `result` that was accumulated before the `(` (which was pushed first).

*   **Initialization:** Initialize `sign` to `1` (positive) and `result` to `0` at the start. This sets up the initial state correctly for the first number.

*   **Data Type for Numbers:** In languages like C++ or Java, consider using `long long` or `long` for `num` and `result` if there's a possibility of intermediate or final results exceeding the range of a standard `int`, although for this specific problem's constraints, `int` might suffice for `result` and `long` for `num` to prevent overflow during number building. Python handles large integers automatically."