# Lowest Common Ancestor of a Binary Search Tree

## Intuition

In a Binary Search Tree (BST), the Lowest Common Ancestor (LCA) of two nodes `p` and `q` has a special property. As you traverse down from the root, the LCA is the first node you encounter where `p` and `q` are in different subtrees. In other words, it's the node where the path to `p` and the path to `q` diverge.

## Pro-tip

Because of the BST property, we don't need to search both subtrees. 
- If both `p` and `q` have values smaller than the current node, the LCA must be in the left subtree.
- If both have values larger, the LCA must be in the right subtree.
- If one is smaller and one is larger (or one is the node itself), then the current node is the LCA.

## Trick

This logic can be implemented very cleanly with an iterative approach. Start at the root and move left or right based on the comparison with `p` and `q`'s values. The loop terminates when you find the LCA, making the solution very efficient (O(H) time and O(1) space).

## Main Concept

This problem is a prime example of how the inherent properties of a **Binary Search Tree** can be exploited to create a much more efficient algorithm compared to finding the LCA in a general binary tree.
