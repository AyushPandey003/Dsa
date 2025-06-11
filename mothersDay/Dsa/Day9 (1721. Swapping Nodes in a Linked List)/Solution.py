class Solution:
    def SwappingNodes(self, head, k):
        if not head or not head.next:
            return head
        
        # Step 1: Find the length of the linked list
        length = 0
        current = head
        while current:
            length += 1
            current = current.next
        
        # Step 2: Find the k-th node from the start and the k-th node from the end
        first_k_node = last_k_node = head
        for _ in range(k - 1):
            first_k_node = first_k_node.next
        
        for _ in range(length - k):
            last_k_node = last_k_node.next
        
        # Step 3: Swap the values of the two nodes
        first_k_node.val, last_k_node.val = last_k_node.val, first_k_node.val
        
        return head
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
result = solution.SwappingNodes(head, k)
while result:
    print(result.val, end=" -> ")
    result = result.next
print("None")