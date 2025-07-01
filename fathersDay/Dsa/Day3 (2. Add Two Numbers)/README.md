# Day 3: Add Two Numbers (LeetCode 2)

## Main Concept

The problem asks us to add two non-negative numbers represented as linked lists. The digits are stored in reverse order, and each of their nodes contains a single digit. We need to return the sum as a linked list in the same format.

For example, if `l1` represents the number 342 (2 -> 4 -> 3) and `l2` represents 465 (5 -> 6 -> 4), the sum should be 807 (7 -> 0 -> 8).

The core idea is to simulate the manual process of adding two numbers, digit by digit, from right to left (least significant to most significant). Since the linked lists store digits in reverse order, we can simply iterate through both lists simultaneously from their heads.

At each step:
1.  Get the values from the current nodes of `l1` and `l2` (or 0 if a list has been exhausted).
2.  Add these values along with any `carry` from the previous step.
3.  Calculate the new `carry` (total sum / 10).
4.  Create a new node for the result list with the digit (total sum % 10).
5.  Move to the next nodes in `l1`, `l2`, and the result list.

This process continues until both input lists are exhausted and there is no remaining `carry`.

## Intuition

The intuition is to mimic elementary arithmetic addition. We process digits from the least significant position (the head of the linked lists) upwards. The `carry` variable is crucial for propagating the tens digit to the next position, just like in manual addition. By building a new linked list for the sum, we ensure that the result is also in the required reverse-digit format.

The use of a dummy head node simplifies the creation of the result list, as we don't need to handle the special case of initializing the first node.

## Pro Tip and Trick

*   **Dummy Head Node:** Always use a **dummy head node** for the result linked list. This is a common and highly effective trick in linked list problems. It simplifies the code by allowing you to always append to `current.next` without needing to check if `current` is the very first node. After the loop, you simply return `dummy_head.next`.

*   **Handling Different Lengths and Final Carry:** The `while` loop condition should be `while l1 or l2 or carry:`. This ensures that the loop continues as long as there are digits in either of the input lists OR if there's a remaining `carry` from the last addition. This elegantly handles cases where one list is longer than the other, or when the sum results in an extra most significant digit (e.g., 5 + 5 = 10, requiring a new node for 1).

*   **Safe Value Retrieval:** When accessing `l1.val` or `l2.val`, always check if `l1` or `l2` is `None`/`null` first. If a list has been exhausted, treat its current value as `0`. This prevents `NullPointerExceptions` (or similar errors) and keeps the code clean:
    ```python
    val1 = (l1.val if l1 else 0)
    val2 = (l2.val if l2 else 0)
    ```
    (Similar logic applies to C++ and Java using `l1 != nullptr ? l1->val : 0;` or `l1 != null ? l1.val : 0;`)

*   **Modular Arithmetic for Digits:** Use the modulo operator (`%`) to get the digit for the current position (`total % 10`) and integer division (`//` or `/`) to get the `carry` for the next position (`total // 10`).