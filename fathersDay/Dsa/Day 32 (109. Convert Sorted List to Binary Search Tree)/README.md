# Convert Sorted List to Binary Search Tree

## Intuition

To create a height-balanced Binary Search Tree (BST) from a sorted list, we should pick the middle element of the list as the root of the BST. The elements to the left of the middle element will form the left subtree, and the elements to the right will form the right subtree. This process can be applied recursively to build the entire tree.

## Pro-tip

The easiest way to implement this is to first convert the linked list to an array. This allows for O(1) access to the middle element, which simplifies the recursive construction of the BST.

## Trick

An alternative, more advanced approach is to use an in-order traversal simulation. Find the middle of the list using the slow and fast pointer technique, make it the root, and then recursively build the left and right subtrees. This avoids the O(N) space complexity of converting the list to an array.

## Main Concept

This problem is about converting a sorted data structure into a height-balanced BST. The key concept is **Divide and Conquer**, where we recursively solve the problem for smaller subproblems (the left and right halves of the list/array).
