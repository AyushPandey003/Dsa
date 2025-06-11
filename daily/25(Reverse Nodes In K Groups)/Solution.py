class Solution:
    def reverseKGroup(self, head, k):
        if not head or k < 1:
            return head
        count = 0
        current = head
        while current:
            count += 1
            current = current.next
        if count < k:
            return head
        prev = None
        current = head
        for _ in range(k):
            next_node = current.next
            current.next = prev
            prev = current
            current = next_node
        head.next = self.reverseKGroup(current, k)
        return prev
k=Solution()
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next
# Creating a linked list for testing
def create_linked_list(values):
    head = ListNode(values[0])
    current = head
    for value in values[1:]:
        current.next = ListNode(value)
        current = current.next
    return head
def print_linked_list(head):
    current = head
    while current:
        print(current.val, end=" -> ")
        current = current.next
    print("None")
# Test the reverseKGroup function
head = create_linked_list([1,2,3,4,5])
k_value = 3
reversed_head = k.reverseKGroup(head, k_value)
print_linked_list(reversed_head)  

    