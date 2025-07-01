# Lowest Common Ancestor of a Binary Tree

## Intuition

The Lowest Common Ancestor (LCA) of two nodes `p` and `q` in a binary tree is the deepest node that has both `p` and `q` as descendants. The search for the LCA can be done with a recursive Depth-First Search (DFS).

## Pro-tip

The recursive strategy is as follows:
1.  **Base Case:** If the current node is `null`, or if it's one of the nodes we're looking for (`p` or `q`), return the current node.
2.  **Recursive Step:** Recursively call the function for the left and right children.
3.  **Combine Results:**
    - If the recursive calls on both the left and right subtrees return non-null values, it means `p` and `q` were found in different subtrees. Therefore, the current node is their LCA.
    - If only one of the calls returns a non-null value, it means both `p` and `q` are in that subtree. Propagate this non-null value up.

## Trick

This recursive approach elegantly handles the case where one node is an ancestor of the other. For instance, if `p` is an ancestor of `q`, the search for `p` will return `p` itself, and the search in the other subtree will return `null`. The function will then correctly return `p` as the LCA.

## Main Concept

This is a classic **Tree Traversal** problem that is best solved with **Recursion** or **Depth-First Search (DFS)**. The solution hinges on processing information from the subtrees to make a decision at the current node.
