from typing import Optional
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next
class Solution:
    def removeDuplicates(self, head: Optional[ListNode]) -> Optional[ListNode]:
        dummy = ListNode(0)
        dummy.next = head
        prev = dummy
        current = head
        
        while current:
            if current.next and current.val == current.next.val:
                while current.next and current.val == current.next.val:
                    current = current.next
                prev.next = current.next
            else:
                prev = prev.next
        
            current = current.next
        
        return dummy.next
solution = Solution()
head = ListNode(1, ListNode(2, ListNode(3, ListNode(3, ListNode(4, ListNode(4, ListNode(5)))))))
result = solution.removeDuplicates(head)
while result:
    print(result.val, end=" -> ")
    result = result.next
print("None")
