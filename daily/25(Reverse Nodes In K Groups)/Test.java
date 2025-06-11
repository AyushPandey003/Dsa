class Test {
    static class ListNode {
        int val;
        ListNode next;
        ListNode(int x) { val = x; }
        ListNode(int x, ListNode next) {
            val = x;
            this.next = next;
        }
    }

    public static void main(String[] args) {
        ListNode head = new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(4, null))));
        System.out.println("List created with head value: " + head.val);
        System.out.println("Dummy node created with value: " + dummy.val);
        while (head != null) {
            System.out.print(head.val + " ");
            head = head.next;
        }
    }
}