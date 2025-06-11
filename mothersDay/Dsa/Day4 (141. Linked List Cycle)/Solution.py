class Solution :
    class ListNode :
        def __init__(self, val=0, next=None) :
            self.val = val
            self.next = next
    def hasCycle(self, head) :
        slow =head
        fast = head
        while fast and fast.next :
            slow = slow.next
            fast = fast.next.next
            if slow == fast :
                return True
        return False
k= Solution()
head = Solution.ListNode(3)
head.next = Solution.ListNode(2)
head.next.next = Solution.ListNode(0)
head.next.next.next = Solution.ListNode(-4)
head.next.next.next.next = head.next 
result = k.hasCycle(head)
print(result)  
