# Validate Binary Search Tree

## Intuition

A Binary Search Tree (BST) has a specific ordering property: for any given node, all values in its left subtree must be less than the node's value, and all values in its right subtree must be greater. This property must hold true for all nodes in the tree, not just the immediate children.

## Pro-tip

A simple check of `node.left.val < node.val` and `node.right.val > node.val` is not enough. We need to ensure that all nodes in the left subtree are less than the current node's value and all nodes in the right subtree are greater. This can be achieved by passing down a valid range (min and max values) for each node.

## Trick

Use a recursive helper function that takes the current node and a `(low, high)` range as arguments. For a node to be valid, its value must be within this range. When recursing to the left child, the upper bound becomes the current node's value. When recursing to the right child, the lower bound becomes the current node's value.

## Main Concept

This problem tests the understanding of the **definition of a Binary Search Tree**. The key is to realize that the validity of a BST is a recursive property that depends on constraints imposed by its ancestors.
