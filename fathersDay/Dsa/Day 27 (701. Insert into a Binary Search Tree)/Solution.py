from typing import Optional
class TreeNode:
    def __init__(self,val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
class Solution:
    def insertIntoBST(self, root: Optional[TreeNode], val: int) -> Optional[TreeNode]:
        if not root:
            return TreeNode(val)
        if val < root.val:
            root.left = self.insertIntoBST(root.left, val)
        else:
            root.right = self.insertIntoBST(root.right, val)
        return root
solution = Solution()
root = TreeNode(4)
root.left = TreeNode(2)
root.right = TreeNode(7)
root.left.left = TreeNode(1)
root.left.right = TreeNode(3)
val = 5
result = solution.insertIntoBST(root, val)
def inorder_traversal(node):
    if node:
        inorder_traversal(node.left)
        print(node.val, end=' ')
        inorder_traversal(node.right)
inorder_traversal(result)  # Output: 1 2 3 4 5 7, as the value 5 is inserted into the BST
print()  # For a new line after the output