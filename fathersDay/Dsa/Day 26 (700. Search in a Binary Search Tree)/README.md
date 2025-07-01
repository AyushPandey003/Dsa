# Search in a Binary Search Tree

## Intuition

The structure of a Binary Search Tree (BST) is designed for efficient searching. The core property is that for any node, all values in its left subtree are smaller, and all values in its right subtree are larger. We can leverage this property to quickly narrow down the search space.

## Pro-tip

Start the search from the root. At each node, compare the target value with the node's value:
- If they are equal, you've found the node.
- If the target value is smaller, you only need to search in the left subtree.
- If the target value is larger, you only need to search in the right subtree.

This process continues until the node is found or you reach a `null` pointer, which means the value is not in the tree.

## Trick

Both recursive and iterative approaches work well. The iterative approach can be slightly more efficient in terms of space because it avoids the overhead of recursive function calls. You can use a `while` loop that continues as long as the current node is not `null` and its value is not the one you're looking for.

## Main Concept

This problem is a fundamental test of understanding the **Binary Search Tree (BST)** property. The ability to discard half of the remaining tree at each step is what gives a BST its logarithmic time complexity for search operations, making it much faster than a linear search in an unsorted array or list.
