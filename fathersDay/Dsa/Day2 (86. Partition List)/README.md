# Day 2: Partition List (LeetCode 86)

## Main Concept

The problem requires us to partition a given linked list around a specific value `x`. This means rearranging the nodes such that all nodes with values less than `x` come before all nodes with values greater than or equal to `x`. Importantly, the relative order of nodes within each of the two partitions (less than `x`, and greater than or equal to `x`) must be preserved.

The core idea is to create two separate, empty linked lists:
1.  One list to store all nodes whose values are less than `x`.
2.  Another list to store all nodes whose values are greater than or equal to `x`.

We iterate through the original linked list. For each node, we check its value against `x` and append it to the appropriate new list. After processing all nodes from the original list, we connect the tail of the "less than `x`" list to the head of the "greater than or equal to `x`" list.

## Intuition

The intuition behind this approach is to effectively "filter" the nodes into two distinct groups based on the partitioning value `x`. By building two separate lists, we naturally preserve the relative order of elements within each group as we append them. Once both groups are formed, simply concatenating them in the correct order (less than `x` first, then greater than or equal to `x`) yields the desired partitioned list.

This method avoids complex in-place manipulations of pointers that could be error-prone and difficult to manage while preserving relative order.

## Pro Tip and Trick

*   **Dummy Nodes:** A common and highly recommended trick for linked list problems, especially those involving building new lists or modifying the head, is to use **dummy nodes**. In this solution, `before_head` and `after_head` are dummy nodes. They simplify the logic significantly because you don't have to worry about special cases for the first node of each new list. You can always append to `dummy.next` and return `dummy.next` as the actual head of the constructed list.

    *   `before_head` acts as a placeholder for the head of the list containing nodes less than `x`.
    *   `after_head` acts as a placeholder for the head of the list containing nodes greater than or equal to `x`.

*   **Maintaining Pointers for Appending:** Keep separate pointers (`before` and `after`) that always point to the *last* node of their respective temporary lists. This allows for `O(1)` appending of new nodes.

*   **Terminating the Second List:** After the loop, it's crucial to set `after.next = None` (or `nullptr` in C++, `null` in Java). This terminates the second list (`after` list) and prevents any potential cycles or unintended connections to the remainder of the original list if the original list had more nodes after the last node moved to the `after` list.

*   **Connecting the Partitions:** The final step is to connect the `before` list to the `after` list: `before.next = after_head.next`. Remember to connect to `after_head.next` (the actual first node of the `after` partition) and not `after_head` itself (which is the dummy node).