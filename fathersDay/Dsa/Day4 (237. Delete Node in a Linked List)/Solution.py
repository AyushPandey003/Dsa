class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next
        
class Solution:
    def DeleteNode(self, node: ListNode) -> None:
        if node is None or node.next is None:
            return 
        node.val = node.next.val
        node.next = node.next.next
        
solution = Solution()
head = ListNode(4, ListNode(5, ListNode(1, ListNode(9))))
node_to_delete = head.next  
solution.DeleteNode(node_to_delete)
current = head
while current:
    print(current.val, end=" -> ")
    current = current.next
print("None")  