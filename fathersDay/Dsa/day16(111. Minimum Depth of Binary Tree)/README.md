## Day 16: Minimum Depth of Binary Tree (Problem 111)

## Main Concept

The "Minimum Depth of Binary Tree" problem asks us to find the shortest path from the root node down to the nearest leaf node. A leaf node is defined as a node that has no children. Unlike maximum depth, where we consider the longest path, here we are interested in the *first* leaf node encountered when traversing the tree.

This problem can be solved using either **Depth-First Search (DFS)** or **Breadth-First Search (BFS)**. However, BFS is generally more efficient for finding the *minimum* depth because it explores the tree level by level, guaranteeing that the first leaf node encountered will be at the minimum depth.

## Intuition

### Recursive Approach (DFS)

The recursive approach for minimum depth is slightly trickier than maximum depth because of how leaf nodes are defined. A node with only one child is *not* a leaf node, and its path continues through its existing child.

1.  **Base Case:** If the `root` is `null` (or `None` in Python), the depth is `0`.
2.  **Leaf Node:** If the current node is a leaf node (i.e., both `left` and `right` children are `null`), its depth is `1`.
3.  **One Child Exists:**
    *   If only the `left` child exists (`right` is `null`), the minimum depth is `1 + minDepth(root.left)`.
    *   If only the `right` child exists (`left` is `null`), the minimum depth is `1 + minDepth(root.right)`.
4.  **Both Children Exist:** If both `left` and `right` children exist, the minimum depth is `1 + min(minDepth(root.left), minDepth(root.right))`.

### Iterative Approach (BFS)

BFS is often the more intuitive and efficient approach for minimum depth because it naturally explores the tree level by level. The first time you encounter a leaf node, you know you've found the minimum depth.

1.  **Initialization:** If the `root` is `null`, return `0`. Otherwise, initialize a queue and add the `root` along with its depth (which is `1`).
2.  **Level-by-Level Traversal:** While the queue is not empty:
    *   Dequeue a node and its current `depth`.
    *   **Check for Leaf:** If the dequeued node is a leaf node (both `left` and `right` children are `null`), then `depth` is the minimum depth of the tree. Return `depth`.
    *   **Enqueue Children:** If the node has a `left` child, enqueue it with `depth + 1`. If it has a `right` child, enqueue it with `depth + 1`.

## Pro Tips and Tricks

*   **BFS for Minimum Depth:** For problems asking for the *minimum* path or depth in a tree, BFS is generally the most straightforward and efficient approach. It guarantees that the first time you reach a target (in this case, a leaf node), it will be via the shortest path.

*   **Distinction from Maximum Depth:** Be careful not to confuse minimum depth with maximum depth. The logic for handling nodes with only one child is different. For maximum depth, you always take the `max` of the left and right subtree depths. For minimum depth, if one child is missing, you *must* go down the existing child's path.

*   **Handling Null Root:** Always handle the `root == null` (or `None`) case first, returning `0`.

*   **Leaf Node Definition:** A node is a leaf if `node.left == null && node.right == null`. This is a critical condition.

*   **Queue for BFS:** Use a queue (e.g., `collections.deque` in Python, `LinkedList` in Java, `std::queue` in C++) to manage the nodes to visit. You'll need to store both the `TreeNode` and its `depth` in the queue.

*   **Pairing Node and Depth:** In BFS, it's common to store pairs (or custom objects) in the queue, where each pair contains a `TreeNode` and its corresponding `depth` from the root. This allows you to track the depth as you traverse.

*   **Time and Space Complexity:**
    *   **BFS:** Time complexity is O(N) in the worst case (where N is the number of nodes), as each node is visited once. Space complexity is O(W) where W is the maximum width of the tree (number of nodes at the widest level), which can be O(N) in the worst case (e.g., a complete binary tree).
    *   **DFS (Recursive):** Time complexity is O(N). Space complexity is O(H) where H is the height of the tree (due to recursion stack), which can be O(N) in the worst case (e.g., a skewed tree).