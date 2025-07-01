# Binary Tree Right Side View

## Intuition

The problem asks us to return the values of the nodes that are visible from the right side of a binary tree, ordered from top to bottom. This means for each level of the tree, we want to capture the rightmost node's value.

## Pro-tip

This problem can be solved using a **Breadth-First Search (BFS)**, also known as a level-order traversal. As we traverse the tree level by level, the last node processed in each level will be the one visible from the right side.

## Trick

When performing BFS, keep track of the number of nodes at the current level. Iterate through all nodes at the current level, and when you process the very last node of that level, add its value to your result list. Then, add its children to the queue for the next level.

## Main Concept

This problem is a good application of **Level Order Traversal (BFS)**. It demonstrates how to process a tree level by level and extract specific information (the rightmost node) from each level.
