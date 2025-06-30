from typing import Optional
class TreeNode:
    def __init__(self,val=0,right=None,left=None):
        self.val = val
        self.left = left
        self.right = right
class Solution1:
    def minDepthIterative(self, root: Optional[TreeNode]) -> int:
        if not root:
            return 0
        
        queue = [(root, 1)]
        while queue:
            node, depth = queue.pop(0)
            if not node.left and not node.right:
                return depth
            if node.left:
                queue.append((node.left, depth + 1))
            if node.right:
                queue.append((node.right, depth + 1))
        return 0

root= TreeNode(1)
root.left = TreeNode(2)
root.right = TreeNode(3)
root.left.left = TreeNode(4)
root.left.right = TreeNode(5)
solution = Solution1()
print(solution.minDepthIterative(root)) 
