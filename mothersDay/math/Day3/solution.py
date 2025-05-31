from typing import Optional

class Listlist:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

class Solution:
    def mergeTwoLists(self, list1: Optional[Listlist], list2: Optional[Listlist]) -> Optional[Listlist]:
        dummy = Listlist(0)
        current = dummy
        while list1 and list2:
            if list1.val < list2.val:
                current.next = list1
                list1 = list1.next
            else:
                current.next = list2
                list2 = list2.next
            current = current.next
        current.next = list1 if list1 else list2
        return dummy.next
sol = Solution()
k = sol.mergeTwoLists(Listlist(1, Listlist(2, Listlist(4))), Listlist(1, Listlist(3, Listlist(4))))
print(k.val)  