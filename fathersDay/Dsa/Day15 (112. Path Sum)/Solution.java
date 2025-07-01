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
    public boolean hasPathSum(TreeNode root, int targetSum) {
        // Base case: if root is null, there's no path, return false.
        if (root == null) {
            return false;
        }
        
        // Subtract current node's value from targetSum
        targetSum -= root.val;
        
        // If it's a leaf node and targetSum is 0, we found a path
        if (root.left == null && root.right == null) {
            return targetSum == 0;
        }
        
        // Recursively check left and right subtrees
        return hasPathSum(root.left, targetSum) || hasPathSum(root.right, targetSum);
    }
}