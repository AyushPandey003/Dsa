class Solution :
    def RemoveNthFromEnd(self, head, n):
        if not head or n <= 0:
            return head
        
        dummy = ListNode(0)
        dummy.next = head
        slow = dummy
        fast = dummy
        
        for _ in range(n):
            if fast:
                fast = fast.next
        
        while fast:
            slow = slow.next
            fast = fast.next
        
        if slow and slow.next:
            slow.next = slow.next.next
        
        return dummy.next
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next
# Example usage
head = ListNode(1)
head.next = ListNode(2)
head.next.next = ListNode(3)
head.next.next.next = ListNode(4)
head.next.next.next.next = ListNode(5)
solution = Solution()
result = solution.RemoveNthFromEnd(head, 2)
while result:
    print(result.val, end=" -> ")
    result = result.next
print("None")
