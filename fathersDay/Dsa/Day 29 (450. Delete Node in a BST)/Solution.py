class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
class Solution:
    def deleteNode(self, root: 'TreeNode', key: int) -> 'TreeNode':
        # Base case: if root is None, return None
        if not root:
            return None
        if key < root.val:
            root.left = self.deleteNode(root.left, key)
        elif key > root.val:
            root.right = self.deleteNode(root.right, key)
        else:
            # Node with only one child or no child
            if not root.left:
                return root.right
            elif not root.right:
                return root.left
        
            min_larger_node = self.getMin(root.right)
            root.val = min_larger_node.val
            root.right = self.deleteNode(root.right, min_larger_node.val)
        return root
    def getMin(self, node: 'TreeNode') -> 'TreeNode':
        while node.left:
            node = node.left
        return node
solution=Solution()
# Example usage:
# Constructing a binary search tree
root = TreeNode(5)
root.left = TreeNode(3)
root.right = TreeNode(6)
root.left.left = TreeNode(2)
root.left.right = TreeNode(4)
root.right.right = TreeNode(7)
key = 3
result = solution.deleteNode(root, key)
# Function to get the minimum value node in a subtree
print(result.val)  # Output: 5, as the node with value 3 is deleted and replaced by the minimum larger node (4)