import java.util.ArrayList;
import java.util.List;

class TreeNode {
    int val;
    TreeNode left;
    TreeNode right;
    TreeNode(int val) { this.val = val; }
}

class Solution {
    public int KthSmallest(TreeNode root, int k) {
        List<Integer> sortedElements = new ArrayList<>();
        inorder(root, sortedElements);
        if (k > 0 && k <= sortedElements.size()) {
            return sortedElements.get(k - 1);
        }
        return -1; // Or throw an exception
    }

    private void inorder(TreeNode node, List<Integer> list) {
        if (node == null) return;
        inorder(node.left, list);
        list.add(node.val);
        inorder(node.right, list);
    }

    public static void main(String[] args) {
        TreeNode root = new TreeNode(3);
        root.left = new TreeNode(1);
        root.right = new TreeNode(4);
        root.left.right = new TreeNode(2);
        Solution solution = new Solution();
        int k = 1;
        int result = solution.KthSmallest(root, k);
        System.out.println(result); // Output: 1
    }
}
