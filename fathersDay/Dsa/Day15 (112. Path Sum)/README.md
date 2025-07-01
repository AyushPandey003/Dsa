## Day 15: Path Sum (Problem 112)

## Main Concept

The "Path Sum" problem asks us to determine if there exists a root-to-leaf path in a binary tree such that the sum of the node values along that path equals a given `targetSum`. A root-to-leaf path means starting from the root and ending at any leaf node (a node with no children).

This problem is a classic application of **Depth-First Search (DFS)**, specifically using recursion, where we explore each path from the root downwards, subtracting the current node's value from the `targetSum` as we go.

## Intuition

The core idea is to traverse the tree and, at each step, reduce the `targetSum` by the value of the current node. When we reach a leaf node, we check if the remaining `targetSum` is zero. If it is, it means we found a path whose sum equals the original `targetSum`.

Here's a breakdown of the recursive intuition:

1.  **Base Case (Empty Tree):** If the `root` is `null` (or `None` in Python), it means we've gone past a leaf node or started with an empty tree. In this case, no path exists, so we return `false`.

2.  **Update `targetSum`:** For the current node, subtract its `val` from the `targetSum`. This `targetSum` now represents the remaining sum we need to find in the subtree rooted at the current node.

3.  **Check for Leaf Node:** If the current node is a leaf node (i.e., both `left` and `right` children are `null`):
    -   We check if the updated `targetSum` is `0`. If it is, we've found a valid path, so we return `true`.
    -   If it's not `0`, this path doesn't sum up to the target, so we return `false`.

4.  **Recursive Calls:** If the current node is not a leaf node, we recursively call `hasPathSum` on its `left` child and its `right` child, passing the updated `targetSum`. We use a logical OR (`||`) because if *either* the left subtree or the right subtree contains a valid path, then the overall condition is met.

This recursive approach naturally explores all possible root-to-leaf paths, effectively performing a depth-first search.

## Pro Tips and Tricks

*   **DFS is Key:** This problem is a perfect candidate for DFS. Both recursive and iterative (using a stack) DFS approaches work well.

*   **Modifying `targetSum`:** The most common and elegant way to solve this recursively is to pass a *modified* `targetSum` down the recursion stack. Each time you visit a node, you subtract its value from the `targetSum` for the next level.

*   **Leaf Node Condition:** The condition for a leaf node is crucial: `node.left == null && node.right == null`. Make sure to check this before making further recursive calls.

*   **Return Early:** The `||` (OR) operator in the recursive calls is important. As soon as one path is found that sums to the `targetSum`, the function will return `true` and stop exploring other paths, which can be a performance optimization.

*   **Handling Negative Numbers:** The approach works correctly even with negative node values, as the `targetSum` will simply decrease (or increase if subtracting a negative number) accordingly.

*   **Iterative Approach (BFS or DFS with Stack):**
    *   **BFS (Queue):** You can use a queue to store pairs of `(node, current_sum)`. When you dequeue a node, add its value to `current_sum`. If it's a leaf, check if `current_sum` equals `targetSum`. Enqueue its children with the updated `current_sum`.
    *   **DFS (Explicit Stack):** Similar to BFS, but use a stack. Push `(root, root.val)` initially. When popping `(node, current_sum)`, if it's a leaf, check `current_sum`. Push children with `current_sum + child.val`.

    While iterative solutions are possible, the recursive solution is often more intuitive and concise for this specific problem.

*   **Clarity:** The recursive solution is often preferred for its readability and direct mapping to the problem's definition.