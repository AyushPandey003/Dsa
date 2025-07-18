class Solution:
    class TreeNode:
        def __init__(self, val=0, left=None, right=None):
            self.val = val
            self.left = left
            self.right = right
    def ZigzagLevelOrder(self, root: TreeNode) -> list[list[int]]:
        if not root:
            return []
        
        result, current_level, left_to_right = [], [root], True
        
        while current_level:
            level_values = [node.val for node in current_level]
            if not left_to_right:
                level_values.reverse()
            result.append(level_values)
            
            next_level = []
            for node in current_level:
                if node.left:
                    next_level.append(node.left)
                if node.right:
                    next_level.append(node.right)
            
            current_level = next_level
            left_to_right = not left_to_right
        
        return result
solution = Solution()
# Example usage:
root = solution.TreeNode(1)
root.left = solution.TreeNode(2)
root.right = solution.TreeNode(3)
root.left.left = solution.TreeNode(4)
root.left.right = solution.TreeNode(5)
result = solution.sumNumbers(root)
print(result)  # Output: 262, as the root-to-leaf numbers are 124 and 125, and their sum is 124 + 125 = 249