class TreeNode:
    def __init__(self,val=0,left=None,right=None):
        self.val=val
        self.left=left
        self.right=right
from typing import List, Optional
class Solution:
    def hasPathSum(self, root: Optional[TreeNode], targetSum: int) -> bool:
        """
        Check if the binary tree has a root-to-leaf path such that the sum of the values along the path equals targetSum.
        """
        if not root:
            return False
        
        targetSum -= root.val
        
        if not root.left and not root.right:  # Leaf node
            return targetSum == 0
        
        return (self.hasPathSum(root.left, targetSum) or 
                self.hasPathSum(root.right, targetSum))
        
# Example usage:
root = TreeNode(5)
root.left = TreeNode(4)
root.right = TreeNode(8)
root.left.left = TreeNode(11)
root.left.left.left = TreeNode(7)
root.left.left.right = TreeNode(2)
root.right.left = TreeNode(13)
root.right.right = TreeNode(4)
root.right.right.right = TreeNode(1)
solution = Solution()
print(solution.hasPathSum(root, 22))  