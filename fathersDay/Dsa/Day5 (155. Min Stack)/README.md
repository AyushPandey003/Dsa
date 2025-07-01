# Day 5: Min Stack (LeetCode 155)

## Main Concept

The problem requires us to design a stack that supports `push`, `pop`, `top`, and `getMin` operations. The `getMin` operation should retrieve the minimum element in the stack in `O(1)` time. This is the key challenge, as a standard stack only allows `O(1)` access to the top element.

The core idea to achieve `O(1)` `getMin` is to maintain **two stacks**:
1.  **`mainStack`:** This is a regular stack that stores all the elements pushed onto it, just like a normal stack.
2.  **`minStack`:** This stack stores the minimum elements encountered so far. Its purpose is to keep track of the minimum value at any given point in the `mainStack`.

Here's how the operations work with two stacks:
*   **`push(val)`:**
    *   Push `val` onto `mainStack`.
    *   If `minStack` is empty or `val` is less than or equal to the current top of `minStack`, push `val` onto `minStack`.
*   **`pop()`:**
    *   Pop an element from `mainStack`.
    *   If the popped element is equal to the current top of `minStack`, then also pop from `minStack`.
*   **`top()`:** Return the top element of `mainStack`.
*   **`getMin()`:** Return the top element of `minStack`.

## Intuition

The intuition behind `minStack` is to always have its top element represent the minimum value currently present in `mainStack`. When a new element is pushed, if it's smaller than or equal to the current minimum, it becomes the new minimum, so we push it onto `minStack`. When an element is popped from `mainStack`, if it was the current minimum, then the *previous* minimum (which is now at the top of `minStack`) becomes the new minimum. By keeping `minStack` synchronized in this way, we can always retrieve the minimum element in constant time.

The `val <= self.min_stack[-1]` (or `val <= minStack.peek()`) condition for pushing to `minStack` is important. Using `<=` ensures that duplicate minimum values are handled correctly. If we only used `<`, and we pushed `5`, then `3`, then `3` again, `minStack` would be `[5, 3]`. If we then popped the first `3` from `mainStack`, `minStack` would also pop `3`, leaving `5` as the minimum, which is incorrect if the second `3` is still in `mainStack`.

## Pro Tip and Trick

*   **Synchronized Stacks:** The key is to keep `mainStack` and `minStack` synchronized. `minStack` only stores values that are potential minimums. When an element is pushed, it's added to `minStack` if it's a new minimum or equal to the current minimum. When an element is popped, if it was the current minimum, it's also popped from `minStack`.

*   **Handling Duplicates:** The condition `val <= self.min_stack[-1]` (or `val <= minStack.peek()`) is crucial for correctly handling duplicate minimum values. If you push `5, 3, 3`, `minStack` should contain `[5, 3, 3]`. If you then pop the first `3` from `mainStack`, you also pop `3` from `minStack`. The second `3` remains in `minStack` as the current minimum.

*   **Space Complexity:** This approach uses `O(N)` space in the worst case, where `N` is the number of elements in the stack (e.g., if elements are pushed in decreasing order, `minStack` will have the same size as `mainStack`).

*   **Time Complexity:** All operations (`push`, `pop`, `top`, `getMin`) are `O(1)` on average, as they involve constant-time stack operations.

*   **Edge Cases:** Consider what happens when the stack is empty for `top()` or `getMin()`. The Python solution returns `None`. In C++ and Java, it's common to throw an exception or return a sentinel value if the problem constraints allow.