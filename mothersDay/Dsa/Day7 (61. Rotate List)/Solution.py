class Solution:
    def RotateList(self, head, k):
        if not head or not head.next or k == 0:
            return head
        
        # Calculate the length of the linked list
        length = 1
        current = head
        while current.next:
            current = current.next
            length += 1
        
        # Normalize k to avoid unnecessary rotations
        k %= length
        if k == 0:
            return head
        
        # Find the new tail (length - k - 1) and new head (length - k)
        new_tail = head
        for _ in range(length - k - 1):
            new_tail = new_tail.next
        
        new_head = new_tail.next
        new_tail.next = None
        
        # Find the old tail and connect it to the old head
        old_tail = new_head
        while old_tail.next:
            old_tail = old_tail.next
        old_tail.next = head
        
        return new_head
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
k = 2
solution = Solution()
result = solution.RotateList(head, k)
while result:
    print(result.val, end=" -> ")
    result = result.next
print("None")