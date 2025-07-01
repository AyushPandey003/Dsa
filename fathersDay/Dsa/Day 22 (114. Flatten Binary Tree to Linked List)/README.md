# Flatten Binary Tree to Linked List

## Intuition

The problem asks us to flatten a binary tree into a "linked list" in-place. This means the `right` child pointer should point to the next node in the pre-order traversal, and the `left` child pointer should always be `null`. The order of nodes in the flattened list should be the same as the pre-order traversal of the original tree.

## Pro-tip

One effective approach is to use a stack (or simulate recursion with a stack). Perform a pre-order traversal. As you visit each node, make its right child point to the next node in the pre-order sequence, and set its left child to `null`.

## Trick

An iterative solution using a stack can be quite elegant. Push the root onto the stack. While the stack is not empty, pop a node. If it has a right child, push it onto the stack. If it has a left child, push it onto the stack. Then, if the stack is not empty, set the current node's right child to the top of the stack. Finally, set the current node's left child to `null`.

## Main Concept

This problem is a good exercise in **Tree Traversal** (specifically pre-order) and **In-place Modification** of tree structures. It requires careful manipulation of pointers to achieve the desired flattened structure.
