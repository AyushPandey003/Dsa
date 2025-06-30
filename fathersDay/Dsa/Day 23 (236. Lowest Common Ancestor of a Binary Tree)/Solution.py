class Solution:
    def LowestCommonAncestor(self, root, p, q):
        if not root:
            return None
        if root == p or root == q:
            return root
        
        left = self.LowestCommonAncestor(root.left, p, q)
        right = self.LowestCommonAncestor(root.right, p, q)
        
        if left and right:
            return root
        return left if left else right
# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
# Example usage:
root = TreeNode(3)
root.left = TreeNode(5)
root.right = TreeNode(1)
root.left.left = TreeNode(6)
root.left.right = TreeNode(2)
root.left.right.left = TreeNode(7)
root.left.right.right = TreeNode(4)
p = root.left  # Node with value 5
q = root.left.right.right  # Node with value 4
solution= Solution()
lca = solution.LowestCommonAncestor(root, p, q)
print(lca.val if lca else None)  # Output: 5, the LCA of nodes 5 and 4