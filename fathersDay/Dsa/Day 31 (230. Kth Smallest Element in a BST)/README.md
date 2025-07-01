# Kth Smallest Element in a BST

## Intuition

The in-order traversal of a Binary Search Tree (BST) visits the nodes in ascending order of their values. Therefore, the k-th smallest element is simply the k-th element that we encounter in an in-order traversal.

## Pro-tip

Instead of collecting all elements into a list and then picking the k-th one, we can optimize by stopping the traversal as soon as we find the k-th element. This can be done by maintaining a counter during the in-order traversal.

## Trick

An iterative in-order traversal using a stack is a great way to solve this problem without recursion. You can process the nodes one by one, decrementing `k` each time you "visit" a node (pop it from the stack). When `k` becomes 0, the current node is your answer.

## Main Concept

This problem leverages a fundamental property of **Binary Search Trees (BSTs)**: an **in-order traversal** (left, root, right) processes the node values in sorted order.
