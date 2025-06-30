class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
class Solution:
    def lowestCommonAncestor(self, root: 'TreeNode', p: 'TreeNode', q: 'TreeNode') -> 'TreeNode':
        # Base case: if root is None, return None
        if not root:
            return None
        
        # If both p and q are smaller than root, LCA lies in left subtree
        if p.val < root.val and q.val < root.val:
            return self.lowestCommonAncestor(root.left, p, q)
        
        # If both p and q are greater than root, LCA lies in right subtree
        elif p.val > root.val and q.val > root.val:
            return self.lowestCommonAncestor(root.right, p, q)
        
        # If we reach here, then root is the LCA of p and q
        else:
            return root
# Example usage:
# Constructing a binary search tree
root = TreeNode(6)
root.left = TreeNode(2)
root.right = TreeNode(8)
root.left.left = TreeNode(0)
root.left.right = TreeNode(4)
root.left.right.left = TreeNode(3)
root.left.right.right = TreeNode(5)
root.right.left = TreeNode(7)
root.right.right = TreeNode(9)
p = root.left  # Node with value 2
q = root.right  # Node with value 8
solution = Solution()
result = solution.lowestCommonAncestor(root, p, q)
print(result.val)  # Output: 6, as the LCA of nodes with values 2 and 8 is 6