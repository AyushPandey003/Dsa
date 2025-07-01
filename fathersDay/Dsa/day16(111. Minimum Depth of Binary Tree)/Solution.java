/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */

import java.util.LinkedList;
import java.util.Queue;

class TreeNode {
    int val;
    TreeNode left;
    TreeNode right;
    TreeNode() {}
    TreeNode(int val) { this.val = val; }
    TreeNode(int val, TreeNode left, TreeNode right) {
        this.val = val;
        this.left = left;
        this.right = right;
    }
}

class Solution {
    // Recursive approach (DFS)
    public int minDepth(TreeNode root) {
        if (root == null) {
            return 0;
        }

        // If it's a leaf node, its depth is 1
        if (root.left == null && root.right == null) {
            return 1;
        }

        // If only right child exists, min depth is 1 + minDepth of right subtree
        if (root.left == null) {
            return 1 + minDepth(root.right);
        }

        // If only left child exists, min depth is 1 + minDepth of left subtree
        if (root.right == null) {
            return 1 + minDepth(root.left);
        }

        // If both children exist, min depth is 1 + min of depths of left and right subtrees
        return 1 + Math.min(minDepth(root.left), minDepth(root.right));
    }

    // Iterative approach (BFS)
    public int minDepthIterative(TreeNode root) {
        if (root == null) {
            return 0;
        }

        Queue<Pair<TreeNode, Integer>> queue = new LinkedList<>();
        queue.offer(new Pair<>(root, 1)); // Offer root and its depth (1)

        while (!queue.isEmpty()) {
            Pair<TreeNode, Integer> current = queue.poll();
            TreeNode currentNode = current.getKey();
            int currentDepth = current.getValue();

            // If current node is a leaf, we found the minimum depth
            if (currentNode.left == null && currentNode.right == null) {
                return currentDepth;
            }

            // Enqueue children with incremented depth
            if (currentNode.left != null) {
                queue.offer(new Pair<>(currentNode.left, currentDepth + 1));
            }
            if (currentNode.right != null) {
                queue.offer(new Pair<>(currentNode.right, currentDepth + 1));
            }
        }
        return 0; // Should not be reached if tree is valid
    }

    // Helper class for Pair (similar to Python's tuple for queue)
    private static class Pair<K, V> {
        private final K key;
        private final V value;

        public Pair(K key, V value) {
            this.key = key;
            this.value = value;
        }

        public K getKey() {
            return key;
        }

        public V getValue() {
            return value;
        }
    }
}