## Day 14: Binary Tree Inorder Traversal (Problem 94)

## Main Concept

Inorder traversal is a type of depth-first traversal for binary trees. In this traversal method, we visit the nodes in the following order:

1.  Traverse the **left subtree**.
2.  Visit the **root node**.
3.  Traverse the **right subtree**.

When applied to a Binary Search Tree (BST), an inorder traversal visits the nodes in ascending order of their values, which is a key property and a common use case for this traversal.

## Intuition

### Recursive Approach

The recursive approach directly mirrors the definition of inorder traversal:

1.  **Base Case:** If the current node is `null` (or `None` in Python), there's nothing to traverse, so we return.
2.  **Left Subtree:** Recursively call the inorder traversal function on the `left` child. This ensures that all nodes in the left subtree are visited before the current node.
3.  **Visit Root:** After the left subtree has been fully traversed, we process the current node (e.g., add its value to a list).
4.  **Right Subtree:** Recursively call the inorder traversal function on the `right` child. This ensures that all nodes in the right subtree are visited after the current node.

The recursion naturally handles the stack-like behavior of keeping track of parent nodes to return to after visiting a child.

### Iterative Approach (using a Stack)

The iterative approach simulates the recursion using an explicit stack:

1.  **Initialization:** Start with the `current` node as the `root` and an empty stack.
2.  **Go Left:** While `current` is not `null`, push `current` onto the stack and move `current` to `current.left`. This process continues until we reach the leftmost node of the current subtree.
3.  **Process Node:** Once `current` becomes `null` (meaning we've gone as far left as possible), pop a node from the stack. This popped node is the next node to be visited in inorder sequence. Add its value to the result list.
4.  **Go Right:** After processing the popped node, set `current` to its `right` child. This prepares for traversing the right subtree of the recently processed node.
5.  **Repeat:** Continue steps 2-4 until `current` is `null` and the stack is empty.

## Pro Tips and Tricks

*   **Recursive vs. Iterative:**
    *   **Recursive:** More concise and often easier to understand due to its direct mapping to the definition. However, it can lead to stack overflow errors for very deep trees due to excessive function calls.
    *   **Iterative:** Avoids recursion depth limits and can be more performant in some cases. It requires a good understanding of how to manually manage the stack to mimic the recursive call stack.

*   **Understanding the Stack in Iterative Traversal:** The stack in the iterative approach holds the ancestors of the `current` node that still need to be visited. When you pop a node, it means you've finished traversing its left subtree, and now it's time to visit the node itself before moving to its right subtree.

*   **TreeNode Definition:** Ensure you have the correct `TreeNode` (or equivalent) class definition for your chosen language, including `val`, `left`, and `right` attributes/pointers.

*   **Return Type:** The problem typically asks for a `List` or `Vector` of integers representing the inorder traversal. Make sure your function collects the values and returns them in the correct data structure.

*   **Edge Cases:** Consider an empty tree (`root` is `null`/`None`). Your solution should gracefully handle this by returning an empty list.