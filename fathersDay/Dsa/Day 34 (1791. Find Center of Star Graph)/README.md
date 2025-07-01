# Find Center of Star Graph

## Intuition

A star graph has a center node that is connected to all other nodes. This means the center node will have a degree of `n-1`, where `n` is the total number of nodes in the graph. All other nodes will have a degree of 1.

## Pro-tip

The center node must be present in every edge. Therefore, we only need to check the first two edges. The node that is common to both edges is the center.

## Trick

If `edges[0][0]` is equal to `edges[1][0]` or `edges[1][1]`, then `edges[0][0]` is the center. Otherwise, `edges[0][1]` must be the center.

## Main Concept

This problem is about understanding the properties of a star graph and using the concept of node degrees to find the center.
