# Binary Tree Level Order Traversal

## Intuition

Level order traversal means visiting all nodes at the current level before moving to the next level. This is a classic application of Breadth-First Search (BFS). We can use a queue to keep track of the nodes to visit. We process nodes level by level, adding their children to the queue for the next level.

## Pro-tip

To separate levels, you can process all nodes currently in the queue, then add their children to the queue. The number of nodes in the queue at the beginning of each iteration of the outer loop represents the number of nodes at the current level.

## Trick

After processing all nodes at a given level, the queue will contain all nodes for the next level. This allows for a clean separation of levels in the output.

## Main Concept

This problem is a fundamental application of **Breadth-First Search (BFS)** on a tree. BFS is ideal for problems where you need to explore a tree level by level, such as finding the shortest path in an unweighted graph or processing nodes at the same depth.
