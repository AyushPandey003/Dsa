# Insert into a Binary Search Tree

## Intuition

To insert a new value into a Binary Search Tree (BST), we must place it in a position that maintains the BST property. This means we need to find the correct leaf position for the new node. We can do this by traversing the tree from the root, comparing the new value with the value of each node we visit.

## Pro-tip

- If the new value is less than the current node's value, we move to the left child.
- If the new value is greater, we move to the right child.

We continue this process until we reach a `null` pointer (an empty spot). This is where the new node should be inserted.

## Trick

The insertion logic can be implemented very elegantly using recursion. The base case for the recursion is when we encounter a `null` node, at which point we create and return the new node. The recursive calls naturally handle the traversal and linking of the new node into the tree.

## Main Concept

This is a fundamental operation on a **Binary Search Tree**. It demonstrates how to modify the tree structure while preserving the core BST property, which is essential for the efficiency of search, insertion, and deletion operations.
