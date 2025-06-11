from typing import List, Optional
import heapq
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

    def __lt__(self, other):
        return self.val < other.val

    def __repr__(self):
        return f"ListNode({self.val})"
    
    def __iter__(self):
        current = self
        while current:
            yield current.val
            current = current.next
class Solution:
    def mergeKLists(self, lists: List[Optional[ListNode]]) -> Optional[ListNode]:
        heap = []
        for idx, node in enumerate(lists):
            if node:
                heapq.heappush(heap, (node.val, idx, node))
        dummy = ListNode(0)
        curr = dummy
        while heap:
            _, idx, node = heapq.heappop(heap)
            curr.next = node
            curr = curr.next
            if node.next:
                heapq.heappush(heap, (node.next.val, idx, node.next))
        return dummy.next
k=Solution()
def create_linked_list(values):
    if not values:
        return None
    head = ListNode(values[0])
    current = head
    for value in values[1:]:
        current.next = ListNode(value)
        current = current.next
    return head
def print_linked_list(head):
    current = head
    values = []
    while current:
        values.append(current.val)
        current = current.next
    return values
lists = [
    create_linked_list([1, 4, 5]),
    create_linked_list([1, 3, 4]),
    create_linked_list([2, 6])
]
merged_head = k.mergeKLists(lists)
print(print_linked_list(merged_head)) 