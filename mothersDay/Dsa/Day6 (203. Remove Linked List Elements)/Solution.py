class Solution:
    def RemoveElements(self, head, val):
        dummy = ListNode(0)
        dummy.next = head
        current = dummy
        
        while current.next:
            if current.next.val == val:
                current.next = current.next.next
            else:
                current = current.next
        
        return dummy.next
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next
# Example usage
k = Solution()
head = ListNode(1)
head.next = ListNode(2)
head.next.next = ListNode(6)
head.next.next.next = ListNode(3)
head.next.next.next.next = ListNode(4)
head.next.next.next.next.next = ListNode(5)
head.next.next.next.next.next.next = ListNode(6)
result = k.RemoveElements(head, 6)
while result:
    print(result.val, end=" -> ")
    result = result.next
print("None")