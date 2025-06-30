class Solution:
    class TreeNode:
        def __init__(self, val=0, left=None, right=None):
            self.val = val
            self.left = left
            self.right = right
    def sumNumbers(self, root: TreeNode) -> int:
        def dfs(node, current_sum):
            if not node:
                return 0
            current_sum = current_sum * 10 + node.val
            if not node.left and not node.right:
                return current_sum
            return dfs(node.left, current_sum) + dfs(node.right, current_sum)
        return dfs(root, 0)
solution = Solution()
# Example usage:
root = solution.TreeNode(1)
root.left = solution.TreeNode(2)
root.right = solution.TreeNode(3)
root.left.left = solution.TreeNode(4)
root.left.right = solution.TreeNode(5)
result = solution.sumNumbers(root)
print(result)  # Output: 262, as the root-to-leaf numbers are 124 and 125, and their sum is 124 + 125 = 249
