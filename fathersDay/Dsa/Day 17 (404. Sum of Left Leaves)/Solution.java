// Definition for a binary tree node.
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
    public int sumOfLeftLeaves(TreeNode root) {
        if (root == null) {
            return 0;
        }

        int sumL = 0;

        // Check if the left child exists and is a leaf node
        if (root.left != null && root.left.left == null && root.left.right == null) {
            sumL += root.left.val;
        }

        // Recursively call for left and right subtrees
        sumL += sumOfLeftLeaves(root.left);
        sumL += sumOfLeftLeaves(root.right);

        return sumL;
    }
}

// Example usage (for testing purposes, not part of the class)
/*
public class Main {
    public static void main(String[] args) {
        Solution sol = new Solution();
        TreeNode root = new TreeNode(3);
        root.left = new TreeNode(9);
        root.right = new TreeNode(20);
        root.right.left = new TreeNode(15);
        root.right.right = new TreeNode(7);
        root.left.left = new TreeNode(4); // Example of a left leaf

        System.out.println("Sum of left leaves: " + sol.sumOfLeftLeaves(root)); // Expected: 9 + 4 = 13
    }
}
*/
