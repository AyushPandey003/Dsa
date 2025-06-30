class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next
class Solution:
    def sortedListToBST(self, head: ListNode) -> TreeNode:
        def to_array(head):
            arr = []
            while head:
                arr.append(head.val)
                head = head.next
            return arr

        def build_bst(nums, l, r):
            if l > r:
                return None
            m = (l + r) // 2
            node = TreeNode(nums[m])
            node.left = build_bst(nums, l, m - 1)
            node.right = build_bst(nums, m + 1, r)
            return node

        nums = to_array(head)
        return build_bst(nums, 0, len(nums) - 1)
# Example usage:
head = ListNode(-10)
head.next = ListNode(-3)
head.next.next = ListNode(0)
head.next.next.next = ListNode(5)
head.next.next.next.next = ListNode(9)
solution = Solution()
result = solution.sortedListToBST(head)
def print_bst(node):
    if not node:
        return
    print_bst(node.left)
    print(node.val, end=' ')
    print_bst(node.right)
print_bst(result)  # Output: -10 -3 0 5 9
