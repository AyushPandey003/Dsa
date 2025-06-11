public class Solution {
    static class ListNode {
        int val;
        ListNode next;
        ListNode(int x) { val = x; }
        ListNode(int x, ListNode next) { 
            val = x; 
            this.next = next; 
        }
    }

    public ListNode swapPairs(ListNode head) {
        if (head == null || head.next == null) {
            return head;
        }
        
        ListNode dummy = new ListNode(0);
        dummy.next = head;
        ListNode prev = dummy;
        
        while (prev.next != null && prev.next.next != null) {
            ListNode first = prev.next;
            ListNode second = first.next;
            first.next = second.next;
            second.next = first;
            prev.next = second;
            prev = first;
            System.out.println(first.val + " " + second.val); 
        }
        // Debugging output
        
        return dummy.next;
    }

    public static void main(String[] args) {
        Solution solution = new Solution(); // Instantiate Solution
        ListNode head = new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(4))));
        ListNode swappedHead = solution.swapPairs(head); 

        
        while (swappedHead != null) {
            System.out.print(swappedHead.val + " ");
            swappedHead = swappedHead.next;
        }
    }
}