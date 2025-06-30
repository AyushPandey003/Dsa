from typing import Optional
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
class Solution:
    def SumLeftLeaves(self, root: Optional[TreeNode]) -> int:
        if not root:
            return 0
        sumL = 0
        if root.left and not root.left.left and not root.left.right:
            sumL += root.left.val
        sumL += self.SumLeftLeaves(root.left)
        sumL += self.SumLeftLeaves(root.right)
        return sumL
    
k=TreeNode(1)
k.left=TreeNode(2)
k.right=TreeNode(3)
k.left.left=TreeNode(4)
k.left.right=TreeNode(5)
solution = Solution()
print(solution.SumLeftLeaves(k))  