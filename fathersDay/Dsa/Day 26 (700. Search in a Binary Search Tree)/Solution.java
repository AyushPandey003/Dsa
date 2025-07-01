class TreeNode {
    int val;
    TreeNode left;
    TreeNode right;
    TreeNode(int val) { this.val = val; }
}

class Solution {
    public TreeNode SearchBST(TreeNode root, int val) {
        if (root == null || root.val == val) {
            return root;
        } else if (val < root.val) {
            return SearchBST(root.left, val);
        } else {
            return SearchBST(root.right, val);
        }
    }

    public static void main(String[] args) {
        Solution solution = new Solution();
        TreeNode root = new TreeNode(4);
        root.left = new TreeNode(2);
        root.right = new TreeNode(7);
        root.left.left = new TreeNode(1);
        root.left.right = new TreeNode(3);
        int val = 2;
        TreeNode result = solution.SearchBST(root, val);
        if (result != null) {
            System.out.println(result.val); // Output: 2
        } else {
            System.out.println("Value not found in the BST");
        }
    }
}
