# Diameter of Binary Tree

## Intuition

The diameter of a binary tree is the length of the longest path between any two nodes in a tree. This path may or may not pass through the root. A key insight is that the longest path between two nodes will always pass through some node, say `X`, such that the path is the sum of the maximum depth of its left subtree and the maximum depth of its right subtree. We need to find the maximum such sum across all nodes in the tree.

We can solve this problem using a recursive approach. For each node, we calculate the depth of its left and right subtrees. The diameter passing through this node would be `left_depth + right_depth`. We keep track of the maximum diameter found so far globally.

## Main Concept

**Depth-First Search (DFS) and Recursion:** The problem can be efficiently solved using a post-order traversal (a type of DFS). For each node, we recursively calculate the depth of its left and right children. While returning the depth of the current node (which is `max(left_depth, right_depth) + 1`), we also update a global maximum diameter by considering the path that passes through the current node (`left_depth + right_depth`).

## Pro Tip and Trick

*   **Global Variable for Diameter:** Instead of passing the diameter around in function arguments, it's often cleaner and more efficient to use a class-level variable (or a global variable in some languages) to store the maximum diameter found so far. This allows the `depth` function to focus solely on calculating depth while implicitly updating the diameter.
*   **Post-Order Traversal Logic:** The crucial part is that the diameter calculation (`left_depth + right_depth`) happens *after* the recursive calls to `depth` for the children have returned their depths. This is characteristic of a post-order traversal, where you process the children first and then the current node.
*   **What `depth` Returns:** The `depth` function should return the *height* of the subtree rooted at the current node. This is `1 + max(depth of left child, depth of right child)`.

## Algorithm Steps

1.  Initialize a global variable `diameter` to 0.
2.  Define a recursive helper function, say `depth(node)`:
    a.  **Base Case:** If `node` is `null`, return 0 (depth of an empty tree).
    b.  **Recursive Step:**
        i.  Recursively call `depth` on `node.left` to get `left_depth`.
        ii. Recursively call `depth` on `node.right` to get `right_depth`.
        iii. Update `diameter = max(diameter, left_depth + right_depth)`. This step calculates the potential diameter if the longest path passes through the current `node`.
        iv. Return `1 + max(left_depth, right_depth)`. This is the height of the current subtree.
3.  Call `depth(root)` from the main `diameterOfBinaryTree` function.
4.  Return the final `diameter` value.
