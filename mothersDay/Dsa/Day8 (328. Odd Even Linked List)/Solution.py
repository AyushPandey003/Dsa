class Solution:
    def OddEvenList(self, head):
        if not head or not head.next:
            return head
        
        odd_head = odd_tail = ListNode(0)
        even_head = even_tail = ListNode(0)
        current = head
        is_odd = True
        while current:
            if is_odd:
                odd_tail.next = current
                odd_tail = odd_tail.next
            else:
                even_tail.next = current
                even_tail = even_tail.next
            current = current.next
            is_odd = not is_odd
        even_tail.next = None
        odd_tail.next = even_head.next
        return odd_head.next
# Example usage
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next
head = ListNode(1)
head.next = ListNode(2)
head.next.next = ListNode(3)
head.next.next.next = ListNode(4)
head.next.next.next.next = ListNode(5)
head.next.next.next.next.next = ListNode(6)
solution = Solution()
result = solution.OddEvenList(head)
while result:
    print(result.val, end=" -> ")
    result = result.next
print("None")
