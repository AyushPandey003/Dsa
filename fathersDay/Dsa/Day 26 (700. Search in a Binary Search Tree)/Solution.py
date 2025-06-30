class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def SearchBST(self, root: TreeNode, val: int) -> TreeNode:
        if not root or root.val == val:
            return root
        elif val < root.val:
            return self.SearchBST(root.left, val)
        else:
            return self.SearchBST(root.right, val)

solution = Solution()
root = TreeNode(4)
root.left = TreeNode(2)
root.right = TreeNode(7)
root.left.left = TreeNode(1)
root.left.right = TreeNode(3)
val = 2
result = solution.SearchBST(root, val)
if result:
    print(result.val)  # Output: 2, as it is the node with the value 2 in the BST
else:
    print("Value not found in the BST")