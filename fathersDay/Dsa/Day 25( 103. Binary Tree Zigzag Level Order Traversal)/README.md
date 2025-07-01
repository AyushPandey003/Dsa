# Binary Tree Zigzag Level Order Traversal

## Intuition

This problem is a variation of the standard level order traversal of a binary tree. The only difference is that the order of nodes at alternate levels needs to be reversed. We can perform a standard Breadth-First Search (BFS) and then, for the levels that require it, reverse the collected node values before adding them to the final result.

## Pro-tip

Use a queue for the level order traversal to keep track of nodes at the current level. A boolean flag, say `left_to_right`, can be used to determine the direction of traversal for the current level. After processing all nodes at a level, simply flip the flag for the next level.

## Trick

Instead of using complex data structures like two stacks or a deque, a simpler approach is to perform a standard level order traversal, gather the node values for the current level into a temporary list, and then reverse this list if the `left_to_right` flag indicates so. This keeps the traversal logic clean and separates the reversal logic.

## Main Concept

This problem is based on the **Breadth-First Search (BFS)** or **Level Order Traversal** algorithm for binary trees. It adds a simple condition to alter the output order for alternate levels.
