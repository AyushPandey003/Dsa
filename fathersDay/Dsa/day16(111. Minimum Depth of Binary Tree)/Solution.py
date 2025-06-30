from typing import Optional

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
class Solution:
    def minDepth(self, root: Optional[TreeNode]) -> int:
        if not root:
            return 0
        if not root.left and not root.right:
            return 1
        if not root.left:
            return self.minDepth(root.right) + 1
        if not root.right:
            return self.minDepth(root.left) + 1
        
        left_depth = self.minDepth(root.left)
        right_depth = self.minDepth(root.right)
        
        return min(left_depth, right_depth) + 1
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
# Example usage:
root = TreeNode(1)
root.left = TreeNode(2)
root.right = TreeNode(3)
root.left.left = TreeNode(4)
root.left.right = TreeNode(5)
solution = Solution()
print(solution.minDepth(root))  # Output: 2
print(solution.minDepthIterative(root))  # Output: 2
