class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
class Solution:
    def isValidBST(self, root: TreeNode) -> bool:
        def isBST(node, low=float('-inf'), high=float('inf')):
            if not node:
                return True
            if not (low < node.val < high):
                return False
            return (isBST(node.left, low, node.val) and
                    isBST(node.right, node.val, high))
        
        return isBST(root)
# Example usage:
root = TreeNode(2)
root.left = TreeNode(1)
root.right = TreeNode(3)
solution = Solution()
result = solution.isValidBST(root)
print(result)  # Output: True, as this is a valid binary search tree