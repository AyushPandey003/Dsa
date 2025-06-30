from typing import Optional
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
class Solution:
    def diameterOfBinaryTree(self, root: Optional[TreeNode]) -> int:
        self.diameter = 0
        
        def depth(node: Optional[TreeNode]) -> int:
            if not node:
                return 0
            
            left_depth = depth(node.left)
            right_depth = depth(node.right)
            
            # Update the diameter at this node
            self.diameter = max(self.diameter, left_depth + right_depth)
            
            # Return the depth of the tree rooted at this node
            return max(left_depth, right_depth) + 1
        
        depth(root)
        return self.diameter
# Example usage:
root = TreeNode(1)
root.left = TreeNode(2)
root.right = TreeNode(3)
root.left.left = TreeNode(4)
root.left.right = TreeNode(5)
solution = Solution()
print(solution.diameterOfBinaryTree(root))  # Output: 3