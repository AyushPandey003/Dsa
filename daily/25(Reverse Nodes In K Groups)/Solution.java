class Solution {
    class ListNode {
        int val;
        ListNode next;
        ListNode(int x) { val = x; }
        ListNode(int x, ListNode next) {
            val = x;
            this.next = next;
        }
    }

    public ListNode reverseKGroup(ListNode head, int k) {
        if (head == null || k <= 1) return head;

        ListNode dummy = new ListNode(0, head);
        ListNode prevGroup = dummy;
        ListNode tail = head;

        int index = 0;

        while (tail != null) {
            index++;
            if (index % k == 0) {
                ListNode start = prevGroup.next;
                ListNode nextGroup = tail.next;

                // Reverse k nodes between start and tail (inclusive)
                reverse(start, tail);

                prevGroup.next = tail;
                start.next = nextGroup;

                prevGroup = start;
                tail = nextGroup;
            } else {
                tail = tail.next;
            }
        }

        return dummy.next;
    }

    private void reverse(ListNode start, ListNode end) {
        ListNode prev = null;
        ListNode curr = start;
        ListNode stop = end.next;

        while (curr != stop) {
            ListNode next = curr.next;
            curr.next = prev;
            prev = curr;
            curr = next;
        }
    }
}