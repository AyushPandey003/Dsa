from typing import List, Optional


class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

def inorder_helper(node: Optional[TreeNode], result: List[int]) -> None:
    """
    Helper function to perform inorder traversal recursively.
    """
    if node is not None:
        inorder_helper(node.left, result)
        result.append(node.val)
        inorder_helper(node.right, result)

def build_tree(nodes: List[Optional[int]]) -> Optional[TreeNode]:
    """
    Builds a binary tree from a list of values (level-order traversal).
    None values denote absent children.
    """
    if not nodes or nodes[0] is None:
        return None
    root = TreeNode(nodes[0])
    queue = [root]
    i = 1
    while queue and i < len(nodes):
        current = queue.pop(0)
        if i < len(nodes) and nodes[i] is not None:
            current.left = TreeNode(nodes[i])
            queue.append(current.left)
        i += 1
        if i < len(nodes) and nodes[i] is not None:
            current.right = TreeNode(nodes[i])
            queue.append(current.right)
        i += 1
    return root

class Solution:
    def inorderTraversal(self, root: Optional[TreeNode]) -> List[int]:
        """
        Perform inorder traversal of a binary tree and return the values in a list.
        """
        result = []
        inorder_helper(root, result)
        return result


# Example usage:
root_list = [1,2,3,4,5,None,8,None,None,6,7,9]
root = build_tree(root_list)
solution = Solution()
print(solution.inorderTraversal(root))  # Output: [4, 2, 6, 5, 7, 1, 3, 8, 9]


