# Sum of Left Leaves

## Problem Description
Given the `root` of a binary tree, return the sum of all its left leaves.

A leaf is a node with no children. A left leaf is a leaf that is the left child of another node.

## Main Concepts

This problem involves traversing a binary tree and identifying specific nodes (left leaves) to sum their values. The core concepts are:

1.  **Binary Tree Traversal:** To visit every node in the tree, we can use various traversal methods like Depth-First Search (DFS) or Breadth-First Search (BFS).
    *   **DFS (Pre-order, In-order, Post-order):** Explores as far as possible along each branch before backtracking. Recursive solutions often naturally follow a DFS pattern.
    *   **BFS (Level-order):** Explores node by node, level by level.

2.  **Leaf Node Identification:** A node is a leaf if both its `left` and `right` children are `null` (or `nullptr` in C++).

3.  **Left Child Identification:** To determine if a leaf is a *left* leaf, we need to check if it's the `left` child of its parent.

## Intuition (Recursive DFS Approach)

The most intuitive way to solve this problem is using a recursive Depth-First Search (DFS) approach.

1.  **Base Case:** If the current `root` is `null`, there are no leaves to sum, so return `0`.

2.  **Identify Left Leaf:** For the current `root` node, check its `left` child:
    *   If `root.left` exists (is not `null`)
    *   AND `root.left` is a leaf node (i.e., `root.left.left` is `null` AND `root.left.right` is `null`)
    *   Then, `root.left` is a left leaf, and its value should be added to our total sum.

3.  **Recursive Calls:** Recursively call the `sumOfLeftLeaves` function on the `root.left` and `root.right` subtrees. The sum returned from these recursive calls should also be added to the total.

4.  **Return Total:** The sum accumulated from the current node's left leaf (if any) and the sums from its left and right subtrees is the final result for that subtree.

## Pro Tips and Tricks

*   **Recursive vs. Iterative:** While recursion is often cleaner for tree problems, an iterative approach using a stack (for DFS) or a queue (for BFS) is also possible. The recursive solution is generally preferred for its conciseness in this type of problem.
*   **Parent Information:** Notice that to identify a *left* leaf, you need information from the *parent* node (i.e., `root.left`). This is why the check `root.left && !root.left.left && !root.left.right` is performed at the parent level, not within the leaf node itself.
*   **Clarity of Conditions:** Be precise with your conditions for identifying a left leaf. It must be a left child AND it must be a leaf (no children of its own).
*   **Handling Nulls:** Always handle `null` (or `nullptr`) checks carefully to prevent `NullPointerExceptions` (Java) or segmentation faults (C++).
*   **Time and Space Complexity:**
    *   **Time Complexity:** O(N), where N is the number of nodes in the tree, as we visit each node once.
    *   **Space Complexity:** O(H) in the worst case, where H is the height of the tree. This is due to the recursion stack. In a skewed tree, H can be N (O(N)), and in a balanced tree, H is log N (O(log N)).

## Example

Consider the tree:

```
    3
   / \
  9  20
 /   / \
4   15  7
```

1.  `sumOfLeftLeaves(3)`:
    *   `root.left` is `9`. `9` is not a leaf (`9.left` is `4`).
    *   Recursively call `sumOfLeftLeaves(9)`.
    *   Recursively call `sumOfLeftLeaves(20)`.

2.  `sumOfLeftLeaves(9)`:
    *   `root.left` is `4`. `4` is a leaf (`4.left` is `null`, `4.right` is `null`). Add `4` to sum.
    *   Recursively call `sumOfLeftLeaves(4)` (returns 0).
    *   Recursively call `sumOfLeftLeaves(null)` (returns 0).
    *   Returns `4`.

3.  `sumOfLeftLeaves(20)`:
    *   `root.left` is `15`. `15` is not a leaf (`15.left` is `null`, `15.right` is `null`).
    *   Recursively call `sumOfLeftLeaves(15)`.
    *   Recursively call `sumOfLeftLeaves(7)`.

4.  `sumOfLeftLeaves(15)`:
    *   `root.left` is `null`.
    *   Returns `0`.

5.  `sumOfLeftLeaves(7)`:
    *   `root.left` is `null`.
    *   Returns `0`.

Combining the results:
*   From `sumOfLeftLeaves(9)`: `4`
*   From `sumOfLeftLeaves(20)`: `0` (since `15` and `7` are not left leaves of `20`)

Total sum = `4`.

Wait, the example in the Python code was `k.left.left=TreeNode(4)` and `k.left=TreeNode(2)`. Let's re-evaluate with the provided Python example:

```
    1
   / \
  2   3
 / \
4   5
```

1.  `sumOfLeftLeaves(1)`:
    *   `root.left` is `2`. `2` is not a leaf (`2.left` is `4`).
    *   Recursively call `sumOfLeftLeaves(2)`.
    *   Recursively call `sumOfLeftLeaves(3)`.

2.  `sumOfLeftLeaves(2)`:
    *   `root.left` is `4`. `4` is a leaf (`4.left` is `null`, `4.right` is `null`). Add `4` to sum.
    *   Recursively call `sumOfLeftLeaves(4)` (returns 0).
    *   Recursively call `sumOfLeftLeaves(5)` (returns 0).
    *   Returns `4`.

3.  `sumOfLeftLeaves(3)`:
    *   `root.left` is `null`.
    *   Returns `0`.

Combining the results:
*   From `sumOfLeftLeaves(2)`: `4`
*   From `sumOfLeftLeaves(3)`: `0`

Total sum = `4`.

This matches the Python example's output of `4`.

