# Delete Node in a BST

## Intuition

To delete a node from a Binary Search Tree (BST), we first need to find it. The search is straightforward due to the BST property. Once found, the deletion process depends on the number of children the node has:
1.  **No children (leaf node):** Simply remove the node.
2.  **One child:** Replace the node with its child.
3.  **Two children:** This is the complex case. We need to replace the node with its in-order successor (the smallest node in its right subtree) or its in-order predecessor (the largest node in its left subtree). After replacing the value, we then recursively delete the successor/predecessor node from its original position.

## Pro-tip

Using the in-order successor is a standard approach. The in-order successor is the leftmost node in the right subtree. This ensures that the BST property is maintained. After copying the successor's value to the node to be deleted, the problem reduces to deleting the successor from the right subtree, which is a simpler case (it will have at most one right child).

## Trick

The implementation is naturally recursive. A helper function to find the minimum element in a subtree is useful for finding the in-order successor.

## Main Concept

This problem is a classic operation on a **Binary Search Tree**. It tests understanding of the BST property and requires careful handling of different cases to maintain that property after deletion.
