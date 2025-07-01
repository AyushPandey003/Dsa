# Day 6: Implement Queue using Stacks (LeetCode 232)

## Main Concept

The problem requires us to implement a queue's basic functionalities (push, pop, peek, empty) using only two stacks. A queue operates on a First-In, First-Out (FIFO) principle, while a stack operates on a Last-In, First-Out (LIFO) principle. The challenge is to reconcile these opposing behaviors.

The core idea is to use two stacks:
1.  **`stack1` (or `in_stack`):** This stack is primarily used for `push` operations. When an element is added to the queue, it is simply pushed onto `stack1`.
2.  **`stack2` (or `out_stack`):** This stack is used for `pop` and `peek` operations. To achieve FIFO behavior, elements are transferred from `stack1` to `stack2` when `stack2` is empty and a `pop` or `peek` operation is requested. This transfer reverses the order of elements, making the oldest element (which should be popped first) appear at the top of `stack2`.

## Intuition

The intuition behind using two stacks to simulate a queue lies in the reversal of order. When you push elements onto `stack1` (e.g., 1, 2, 3), they are stored as [3, 2, 1] (top to bottom). If you then pop them all and push them onto `stack2`, they will be pushed in the order 3, 2, 1 onto `stack2`, resulting in `stack2` being [1, 2, 3] (top to bottom). Now, the element at the top of `stack2` (which is 1) is the first element that was originally pushed into `stack1`, thus achieving FIFO.

This strategy ensures that the element that has been in the queue the longest is always at the top of `stack2` when a `pop` or `peek` operation is needed.

## Pro Tip and Trick

*   **Lazy Transfer (Amortized O(1) Complexity):** The most important optimization is to perform the transfer from `stack1` to `stack2` *only when `stack2` is empty* and a `pop` or `peek` operation is called. This is known as lazy transfer. If `stack2` already contains elements, it means they are already in the correct FIFO order, so there's no need to transfer from `stack1`.

    *   **`push(x)`:** Always `stack1.push(x)`. This is an `O(1)` operation.
    *   **`pop()` and `peek()`:**
        1.  Check if `stack2` is empty. If it is, then:
        2.  While `stack1` is not empty, pop elements from `stack1` and push them onto `stack2`. This reverses their order.
        3.  Once `stack2` is populated (or if it was never empty), perform the `pop()` or `peek()` operation on `stack2`.

*   **Amortized Time Complexity:** While a single `pop` or `peek` operation might take `O(N)` time in the worst case (when all elements from `stack1` need to be transferred), the *amortized* time complexity for both `pop` and `peek` is `O(1)`. This is because each element is pushed onto `stack1` once and then popped from `stack1` and pushed onto `stack2` once, and finally popped from `stack2` once. Over a sequence of operations, the total cost per element is constant.

*   **`empty()` Method:** The queue is empty if and only if both `stack1` and `stack2` are empty.

*   **Handling Empty Queue for `pop` and `peek`:** In some implementations, `pop` and `peek` might return a default value or throw an exception if the queue is empty. The provided Python solution returns -1, which might not be suitable for all use cases if -1 is a valid queue element. A more robust solution would be to throw an exception or handle it based on problem constraints.