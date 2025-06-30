from typing import List
class Solution:
    def CenterOfStarGraph(self, edges: List[List[int]]) -> int:
        degree = {}
        for u, v in edges:
            degree[u] = degree.get(u, 0) + 1
            degree[v] = degree.get(v, 0) + 1
        n = len(edges) + 1
        for node, deg in degree.items():
            if deg == n - 1:
                return node
        
        return -1
# Example usage:
solution= Solution()
edges = [[1, 2], [2, 3], [4, 2], [1, 4], [1, 3]]
result = solution.CenterOfStarGraph(edges)
print(result)  # Output: 2 (the center of the star graph)
