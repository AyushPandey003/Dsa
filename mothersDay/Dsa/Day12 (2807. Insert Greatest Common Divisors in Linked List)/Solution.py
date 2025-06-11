from typing import Optional

class Solution:
    def InsertGCD(self, head: Optional['ListNode']) -> Optional['ListNode']:
        if not head or not head.next:
            return head
        
        def gcd(a, b):
            while b:
                a, b = b, a % b
            return a
        
        dummy = ListNode(0)
        dummy.next = head
        current = dummy
        
        while current and current.next and current.next.next:
            first = current.next
            second = current.next.next

            g = gcd(first.val, second.val)

            new_node = ListNode(g)
            new_node.next = second
            first.next = new_node
            current = new_node

        return dummy.next
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next
# Example usage
head = ListNode(18)
head.next = ListNode(6)
head.next.next = ListNode(10)
head.next.next.next = ListNode(3)
solution = Solution()
result = solution.InsertGCD(head)
while result:
    print(result.val, end=" -> ")
    result = result.next
print("None")

