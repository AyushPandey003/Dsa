# Maximum Depth of Binary Tree

## Intuition

The maximum depth of a binary tree is the number of nodes along the longest path from the root node down to the farthest leaf node. This problem can be solved recursively. The depth of a node is 1 plus the maximum depth of its children.

## Pro-tip

- If the root is `null`, the depth is 0.
- Otherwise, the depth is 1 (for the current node) plus the maximum of the depths of its left and right subtrees.

## Trick

This problem is a classic example of a recursive solution. The base case is an empty tree, and the recursive step combines the results from the left and right subtrees.

## Main Concept

This problem is a fundamental application of **Recursion** and **Tree Traversal** (specifically, Depth-First Search). It demonstrates how to break down a problem into smaller, self-similar subproblems.
