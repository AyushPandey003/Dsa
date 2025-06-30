from typing import Optional
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
class solution:
    def flatten(self, root: Optional[TreeNode]) -> None:
        if not root:
            return
        
        # Initialize a stack to keep track of nodes
        stack = [root]
        
        while stack:
            current = stack.pop()
            
            # If the current node has a right child, push it onto the stack
            if current.right:
                stack.append(current.right)
            
            # If the current node has a left child, push it onto the stack
            if current.left:
                stack.append(current.left)
            
            # Reassign the left and right pointers
            if stack:
                current.right = stack[-1]  # The next node in the stack becomes the right child
            current.left = None  # Set left child to None
        return root
solution = solution()
# Example usage:
root = TreeNode(1)
root.left = TreeNode(2)
root.right = TreeNode(5)
root.left.left = TreeNode(3)
root.left.right = TreeNode(4)
root.right.right = TreeNode(6)
solution.flatten(root)
for node in [root, root.right, root.right.right, root.right.right.right]:
    print(node.val if node else None, end=' ')
