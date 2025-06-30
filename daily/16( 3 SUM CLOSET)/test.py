# import requests

# # API Keys
# NEWS_API_KEY = "c142629ef10a4b56aca8d55141f21e5b"
# ALPHA_VANTAGE_API_KEY = "IX128VDP4ZAJRYZU"
# FINNHUB_API_KEY = "d03q9ahr01qm4vp3c89gd03q9ahr01qm4vp3c8a0"
# MARKETAUX_API_KEY = "emMtQtR1vOKpkJyeeGFd3tnEqYpBXm6NJoLmsfn3"
# MARKETSTACK_API_KEY = "b1aba5a2a8833d4f15f0070da7e3a3d6"

# # Function to test NewsAPI
# def test_news_api():
#     url = f"https://newsapi.org/v2/top-headlines?country=in&apiKey={NEWS_API_KEY}"
#     try:
#         response = requests.get(url)
#         print("NewsAPI Response:")
#         print(response.status_code)
#         print(response.json())
#     except Exception as e:
#         print(f"NewsAPI Error: {e}")

# # Function to test Alpha Vantage
# def test_alpha_vantage():
#     url = f"https://www.alphavantage.co/query?function=TIME_SERIES_INTRADAY&symbol=IBM&interval=5min&apikey={ALPHA_VANTAGE_API_KEY}&datatype=csv"
#     try:
#         response = requests.get(url)
#         print("Alpha Vantage Response:")
#         print(response.status_code)
#         print(response.json())
#     except Exception as e:
#         print(f"Alpha Vantage Error: {e}")

# # Function to test Finnhub
# def test_finnhub():
#     url = f"https://finnhub.io/api/v1/quote?symbol=AAPL&token={FINNHUB_API_KEY}"
#     try:
#         response = requests.get(url)
#         print("Finnhub Response:")
#         print(response.status_code)
#         print(response.json())
#     except Exception as e:
#         print(f"Finnhub Error: {e}")

# # Function to test MarketAux
# def test_marketaux():
#     url = f"https://api.marketaux.com/v1/news/all?symbols=TSLA&api_token={MARKETAUX_API_KEY}"
#     try:
#         response = requests.get(url)
#         print("MarketAux Response:")
#         print(response.status_code)
#         print(response.json())
#     except Exception as e:
#         print(f"MarketAux Error: {e}")

# # Function to test Marketstack
# def test_marketstack():
#     url = f"http://api.marketstack.com/v1/eod?access_key={MARKETSTACK_API_KEY}&symbols=AAPL"
#     try:
#         response = requests.get(url)
#         print("Marketstack Response:")
#         print(response.status_code)
#         print(response.json())
#     except Exception as e:
#         print(f"Marketstack Error: {e}")

# # Run tests
# if __name__ == "__main__":
#     print("Testing API Keys...\n")
#     test_news_api()
#     print("\n" + "="*50 + "\n")
#     test_alpha_vantage()
#     print("\n" + "="*50 + "\n")
#     test_finnhub()
#     print("\n" + "="*50 + "\n")
#     test_marketaux()
#     print("\n" + "="*50 + "\n")
#     test_marketstack()


from typing import Optional

def create_binary_tree(arr):
    class TreeNode:
        def __init__(self,val):
            self.val = val
            self.left = None
            self.right = None
    if not arr:
        return None
    
    mid = len(arr) // 2
    root = TreeNode(arr[mid])
    
    root.left = create_binary_tree(arr[:mid])
    root.right = create_binary_tree(arr[mid + 1:])
    
    return root

# Example usage
arr = [1, 2, 3, 4, 5, 6, 7]
root = create_binary_tree(arr)
    
def inorder_traversal(node):
    if node is None:
        return []
    return inorder_traversal(node.left) + [node.val] + inorder_traversal(node.right)
def postorder_traversal(node):
    if node is None:
        return []
    return postorder_traversal(node.left) + postorder_traversal(node.right) + [node.val]
def preorder_traversal(node):
    if node is None:
        return []
    return [node.val] + preorder_traversal(node.left) + preorder_traversal(node.right)
def level_order_traversal(node):
    if node is None:
        return []
    queue = [node]
    result = []
    while queue:
        current = queue.pop(0)
        result.append(current.val)
        if current.left:
            queue.append(current.left)
        if current.right:
            queue.append(current.right)
    return result
def zigzag_level_order_traversal(node):
    if node is None:
        return []
    queue = [node]
    result = []
    left_to_right = True
    while queue:
        level_size = len(queue)
        level_nodes = []
        for _ in range(level_size):
            current = queue.pop(0)
            if left_to_right:
                level_nodes.append(current.val)
            else:
                level_nodes.insert(0, current.val)
            if current.left:
                queue.append(current.left)
            if current.right:
                queue.append(current.right)
        result.append(level_nodes)
        left_to_right = not left_to_right
    return result
def reverse_level_order_traversal(node):
    if node is None:
        return []
    queue = [node]
    stack = []
    while queue:
        current = queue.pop(0)
        stack.append(current.val)
        if current.right:
            queue.append(current.right)
        if current.left:
            queue.append(current.left)
    return stack[::-1]
def boundary_traversal(node):
    if node is None:
        return []
    
    def left_boundary(node):
        if node is None or (node.left is None and node.right is None):
            return []
        return [node.val] + left_boundary(node.left) if node.left else [node.val] + left_boundary(node.right)

    def right_boundary(node):
        if node is None or (node.left is None and node.right is None):
            return []
        return right_boundary(node.right) + [node.val] if node.right else right_boundary(node.left) + [node.val]

    def leaves(node):
        if node is None:
            return []
        if node.left is None and node.right is None:
            return [node.val]
        return leaves(node.left) + leaves(node.right)

    return [node.val] + left_boundary(node.left) + leaves(node.left) + leaves(node.right) + right_boundary(node.right)
def spiral_order_traversal(node):
    if node is None:
        return []
    queue = [node]
    result = []
    left_to_right = True
    while queue:
        level_size = len(queue)
        level_nodes = []
        for _ in range(level_size):
            current = queue.pop(0)
            if left_to_right:
                level_nodes.append(current.val)
            else:
                level_nodes.insert(0, current.val)
            if current.left:
                queue.append(current.left)
            if current.right:
                queue.append(current.right)
        result.extend(level_nodes)
        left_to_right = not left_to_right
    return result
def vertical_order_traversal(node):
    if node is None:
        return []
    
    from collections import defaultdict, deque
    
    column_table = defaultdict(list)
    queue = deque([(node, 0)])  # (node, column_index)
    
    while queue:
        current, column_index = queue.popleft()
        column_table[column_index].append(current.val)
        
        if current.left:
            queue.append((current.left, column_index - 1))
        if current.right:
            queue.append((current.right, column_index + 1))
    
    # Sort the columns and return the result
    sorted_columns = sorted(column_table.keys())
    return [column_table[col] for col in sorted_columns]
def diagonal_traversal(node):
    if node is None:
        return []
    
    from collections import defaultdict, deque
    
    diagonal_map = defaultdict(list)
    queue = deque([(node, 0)])  # (node, diagonal_index)
    
    while queue:
        current, diagonal_index = queue.popleft()
        diagonal_map[diagonal_index].append(current.val)
        
        if current.left:
            queue.append((current.left, diagonal_index + 1))
        if current.right:
            queue.append((current.right, diagonal_index))
    
    # Sort the diagonals and return the result
    sorted_diagonals = sorted(diagonal_map.keys())
    return [diagonal_map[diag] for diag in sorted_diagonals]
def boundary_traversal(node):
    if node is None:
        return []
    
    def left_boundary(node):
        if node is None or (node.left is None and node.right is None):
            return []
        return [node.val] + left_boundary(node.left) if node.left else [node.val] + left_boundary(node.right)

    def right_boundary(node):
        if node is None or (node.left is None and node.right is None):
            return []
        return right_boundary(node.right) + [node.val] if node.right else right_boundary(node.left) + [node.val]

    def leaves(node):
        if node is None:
            return []
        if node.left is None and node.right is None:
            return [node.val]
        return leaves(node.left) + leaves(node.right)

    return [node.val] + left_boundary(node.left) + leaves(node.left) + leaves(node.right) + right_boundary(node.right)
def print_tree(node, level=0):
    if node is not None:
        print_tree(node.right, level + 1)
        print(' ' * 4 * level + '->', node.val)
        print_tree(node.left, level + 1)
        
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

def sumNumbers(self, root: Optional[TreeNode]) -> int:
    def dfs(node, current_sum):
        if not node:
            return 0
        current_sum = current_sum * 10 + node.val
        if not node.left and not node.right:  # Leaf node
            return current_sum
        return dfs(node.left, current_sum) + dfs(node.right, current_sum)

    return dfs(root, 0)
def maxDepth(node):
    if node is None:
        return 0
    left_depth = maxDepth(node.left)
    right_depth = maxDepth(node.right)
    return max(left_depth, right_depth) + 1
def minDepth(node):
    if node is None:
        return 0
    if node.left is None and node.right is None:
        return 1
    if node.left is None:
        return minDepth(node.right) + 1
    if node.right is None:
        return minDepth(node.left) + 1
    return min(minDepth(node.left), minDepth(node.right)) + 1


if __name__ == "__main__":
    print("Inorder Traversal:", inorder_traversal(root))
    print("Postorder Traversal:", postorder_traversal(root))
    print("Preorder Traversal:", preorder_traversal(root))
    print("Level Order Traversal:", level_order_traversal(root))
    print("Zigzag Level Order Traversal:", zigzag_level_order_traversal(root))
    print("Reverse Level Order Traversal:", reverse_level_order_traversal(root))
    print("Boundary Traversal:", boundary_traversal(root))
    print("Spiral Order Traversal:", spiral_order_traversal(root))
    print("Vertical Order Traversal:", vertical_order_traversal(root))
    print("Diagonal Traversal:", diagonal_traversal(root))
    print("tree structure:",print_tree(root))
    