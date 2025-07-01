# Day 4: Delete Node in a Linked List (LeetCode 237)

## Main Concept

This problem presents a unique twist on linked list deletion: we are given direct access to the `node` that needs to be deleted, rather than the `head` of the linked list. Furthermore, it's guaranteed that the given node is not the tail node and will always be a valid node in the list.

Since we don't have access to the previous node (which is typically required to change its `next` pointer to bypass the node to be deleted), we must use a different strategy:

1.  **Copy the value:** Copy the value of the `next` node into the `node` that is to be "deleted". This effectively overwrites the value of the current node with the value of its successor.
2.  **Bypass the next node:** Change the `next` pointer of the current `node` to point to the node *after* its original `next` node (`node.next.next`). This effectively removes the original `next` node from the linked list.

In essence, we are not truly deleting the `node` itself, but rather overwriting its content and then deleting its *successor* from the list, making it appear as if the original `node` was removed.

## Intuition

The intuition behind this approach stems from the constraint that we only have access to the node to be deleted and not its predecessor. To remove a node from a singly linked list, you typically need to modify the `next` pointer of the node *before* it. Since we can't do that, the alternative is to make the current node *become* its successor. By copying the successor's value and then linking past the successor, the current node effectively takes on the identity of its successor, and the successor is then removed.

This method works because the problem only cares about the sequence of values in the list, not the specific memory addresses of the nodes themselves (as long as the list remains valid).

## Pro Tip and Trick

*   **The "Copy and Skip" Technique:** This problem is a classic example of the "copy and skip" or "copy next" technique for deleting a node when only the node itself is given. It's a clever workaround for the limitation of singly linked lists.

*   **Edge Cases (though constrained by problem):** While the problem statement guarantees the node is not the tail and is valid, in a general scenario, you would need to handle:
    *   `node` being `None`/`null`.
    *   `node.next` being `None`/`null` (meaning `node` is the tail). In such a case, this technique wouldn't work, and you'd typically need the head of the list or the previous node.

*   **Memory Management (C++):** In languages like C++ where manual memory management is common, after `node->next = node->next->next;`, you should `delete` the original `node->next` to prevent memory leaks. Python and Java have garbage collectors, so this step is not explicitly required by the programmer.

*   **Visualizing the Change:** It helps to visualize the pointers. If you have `A -> B -> C -> D` and you want to delete `B` (given `B`):
    1.  Copy `C`'s value to `B`: `A -> (B=C) -> C -> D`
    2.  Make `B` point to `D`: `A -> (B=C) -> D` (and `C` is now effectively bypassed and can be garbage collected/deleted).

This trick is specific to scenarios where you are given the node to delete and it's not the last node.