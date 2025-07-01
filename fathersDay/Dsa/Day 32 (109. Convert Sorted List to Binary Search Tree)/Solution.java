import java.util.ArrayList;
import java.util.List;

class TreeNode {
    int val;
    TreeNode left;
    TreeNode right;
    TreeNode(int val) { this.val = val; }
}

class ListNode {
    int val;
    ListNode next;
    ListNode(int val) { this.val = val; }
}

class Solution {
    public TreeNode sortedListToBST(ListNode head) {
        List<Integer> nums = toArray(head);
        return buildBst(nums, 0, nums.size() - 1);
    }

    private List<Integer> toArray(ListNode head) {
        List<Integer> arr = new ArrayList<>();
        while (head != null) {
            arr.add(head.val);
            head = head.next;
        }
        return arr;
    }

    private TreeNode buildBst(List<Integer> nums, int l, int r) {
        if (l > r) {
            return null;
        }
        int m = l + (r - l) / 2;
        TreeNode node = new TreeNode(nums.get(m));
        node.left = buildBst(nums, l, m - 1);
        node.right = buildBst(nums, m + 1, r);
        return node;
    }

    public static void main(String[] args) {
        ListNode head = new ListNode(-10);
        head.next = new ListNode(-3);
        head.next.next = new ListNode(0);
        head.next.next.next = new ListNode(5);
        head.next.next.next.next = new ListNode(9);
        Solution solution = new Solution();
        TreeNode result = solution.sortedListToBST(head);
        printBst(result);
    }

    public static void printBst(TreeNode node) {
        if (node == null) {
            return;
        }
        printBst(node.left);
        System.out.print(node.val + " ");
        printBst(node.right);
    }
}
