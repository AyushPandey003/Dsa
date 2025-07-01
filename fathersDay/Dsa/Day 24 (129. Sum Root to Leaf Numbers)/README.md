# Sum Root to Leaf Numbers

## Intuition

The problem asks for the sum of all numbers formed by root-to-leaf paths in a binary tree. For example, a path `1 -> 2 -> 3` represents the number 123. This suggests a traversal of the tree from the root down to each leaf, keeping track of the number formed along the path.

## Pro-tip

A Depth-First Search (DFS) approach is a natural fit for this problem. We can use a recursive helper function that takes the current node and the number formed so far (`current_sum`) as arguments. As we traverse down, we update the `current_sum`.

## Trick

The key to forming the number is the update step: `current_sum = current_sum * 10 + node.val`. This effectively shifts the existing digits to the left and adds the new digit. When we reach a leaf node (a node with no children), we have formed a complete number, which we can then return. The results from all leaf paths are summed up by the recursive calls.

## Main Concept

This problem is a classic example of **Depth-First Search (DFS)** on a tree. It involves passing state (the `current_sum`) down through the recursive calls to build a solution incrementally.
