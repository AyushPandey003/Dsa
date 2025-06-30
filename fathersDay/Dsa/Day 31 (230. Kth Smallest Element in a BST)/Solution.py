class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
class Solution:
    def KthSmallest(self, root: TreeNode, k: int) -> int:
        def inorder(node):
            if not node:
                return []
            return inorder(node.left) + [node.val] + inorder(node.right)
        
        # Perform in-order traversal to get sorted elements
        sorted_elements = inorder(root)
        
        # Return the k-th smallest element (1-indexed)
        return sorted_elements[k - 1] if 0 < k <= len(sorted_elements) else None
# Example usage:
root = TreeNode(3)
root.left = TreeNode(1)
root.right = TreeNode(4)
root.left.right = TreeNode(2)
solution = Solution()
k = 1
result = solution.KthSmallest(root, k)
print(result)  # Output: 1, as it is the 1st smallest element in the BST