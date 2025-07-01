# Remove Duplicates from Sorted List II - LeetCode 82

## Main Concept: Two Pointers with a Dummy Node

The problem requires removing all nodes that have duplicate numbers, leaving only distinct numbers from the original sorted linked list. The core concept involves using two pointers, `prev` and `current`, along with a `dummy` node to handle edge cases.

1.  **Dummy Node:** Create a `dummy` node and point its `next` to the head of the original list. This simplifies operations, especially if the head itself needs to be removed due to duplication.
2.  **Two Pointers:**
    *   `prev`: Points to the node *before* the `current` node. This pointer is crucial for modifying the `next` reference to skip duplicate sequences.
    *   `current`: Iterates through the linked list.
3.  **Duplicate Detection and Skipping:**
    *   Iterate through the list using `current`.
    *   If `current` and `current.next` have the same value, it indicates the start of a duplicate sequence.
    *   Use an inner loop to advance `current` past *all* nodes with that duplicate value.
    *   Once the inner loop finishes, `current` will be at the last node of the duplicate sequence. At this point, `prev.next` should be set to `current.next`, effectively bypassing the entire duplicate sequence.
    *   If `current` and `current.next` do not have the same value (or `current.next` is null), it means `current` is a unique node (or the last node). In this case, simply advance `prev` to `current`.

## Intuition

Imagine you're walking through a sorted list of numbers. Your goal is to keep only the numbers that appear exactly once. If you see a number, and the very next number is the same, you know you've found a duplicate. You can't keep *either* of them. So, you keep walking past all instances of that duplicate number until you find a different one. Once you find that different number, you connect the node *before* the duplicate sequence directly to this new, different number, effectively cutting out all the duplicates.

If you see a number, and the next number is different (or there is no next number), then you know the current number is unique (at least in this immediate context), so you can safely keep it and move your 'previous' marker to this number.

## Pro Tip & Trick

-   **Edge Cases with Dummy Node:** The `dummy` node is a lifesaver for linked list problems. It allows you to treat the head of the list like any other node, avoiding special checks for when the head itself is a duplicate or needs to be removed.
-   **Sorted List Advantage:** The fact that the list is sorted is key. It guarantees that all duplicate values will be contiguous, simplifying the detection and skipping logic.
-   **Careful Pointer Management:** Pay close attention to how `prev` and `current` are updated. `prev` only moves forward when `current` is *not* part of a duplicate sequence. `current` always moves forward.
-   **Visual Tracing:** For complex linked list manipulations, drawing out the list and tracing the pointer movements step-by-step with an example can be incredibly helpful in debugging and understanding the logic.
