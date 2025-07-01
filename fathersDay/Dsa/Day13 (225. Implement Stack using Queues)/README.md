## Day 13: Implement Stack using Queues (Problem 225)

## Main Concept

The "Implement Stack using Queues" problem challenges us to simulate the Last-In, First-Out (LIFO) behavior of a stack using one or more First-In, First-Out (FIFO) queues. The key is to ensure that the most recently added element (the "top" of the stack) is always readily accessible at the front of the queue.

The common approach involves using a single queue and making the `push` operation the more complex one, while `pop` and `top` remain efficient.

## Intuition

1.  **`push(x)` Operation:**
    -   When a new element `x` is pushed, it is initially added to the back of the queue. At this point, `x` is the newest element, but it's not at the front (which represents the stack's top).
    -   To make `x` the new "top" (i.e., the element at the front of the queue), all existing elements that were previously in the queue must be moved from the front to the back, one by one. This effectively rotates the queue until `x` is at the front.
    -   For example, if the queue is `[A, B, C]` (A is front) and we push `D`:
        -   Add `D`: `[A, B, C, D]`
        -   Move `A` to back: `[B, C, D, A]`
        -   Move `B` to back: `[C, D, A, B]`
        -   Move `C` to back: `[D, A, B, C]`
        Now `D` is at the front, ready to be popped.

2.  **`pop()` Operation:**
    -   Since the `push` operation ensures that the most recently added element is always at the front of the queue, `pop()` simply involves removing and returning the element from the front of the queue.

3.  **`top()` Operation:**
    -   Similarly, `top()` involves peeking at (retrieving without removing) the element at the front of the queue.

4.  **`empty()` Operation:**
    -   This simply checks if the underlying queue is empty.

## Pro Tips and Tricks

*   **Single Queue Efficiency:** The single-queue approach, where `push` is O(N) and `pop`/`top` are O(1), is generally preferred for its simplicity and often better performance in scenarios where `pop` and `top` are called more frequently than `push`.

*   **Number of Rotations in `push`:** When pushing a new element `x`, you need to move `N-1` elements from the front to the back, where `N` is the size of the queue *after* `x` has been added. This ensures `x` ends up at the front.

*   **Alternative (Two Queues):** Another way to implement this is using two queues. One queue (`main_q`) holds the elements, and the other (`temp_q`) is used during `pop`. When `pop` is called, all elements except the last one are moved from `main_q` to `temp_q`. The last element in `main_q` is then popped. Finally, `main_q` and `temp_q` are swapped. In this approach, `push` is O(1) and `pop` is O(N). Choose the approach based on the expected frequency of `push` vs. `pop` operations.

*   **Language-Specific Queue Implementations:**
    *   **Python:** `collections.deque` is ideal for queue operations as `append` and `popleft` are O(1).
    *   **Java:** `java.util.LinkedList` implements the `Queue` interface and provides `add()`, `remove()`, `peek()`, and `isEmpty()`.
    *   **C++:** `std::queue` provides `push()`, `pop()`, `front()`, and `empty()`. You'll need to manually implement the rotation logic for `push` by repeatedly `push`ing `front()` and then `pop()`ing `front()`.

*   **Edge Cases:** Consider an empty stack. `pop()` and `top()` should handle this gracefully (e.g., by throwing an exception or returning a default value, depending on problem constraints).