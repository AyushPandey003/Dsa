from typing import List
class Solution:
    def FindJudge(self, n: int, trust: List[List[int]]) -> int:
        if n == 1 and not trust:
            return 1
        
        trust_count = [0] * (n + 1)
        trusted_by = [0] * (n + 1)
        
        for a, b in trust:
            trust_count[a] += 1
            trusted_by[b] += 1
        
        for i in range(1, n + 1):
            if trust_count[i] == 0 and trusted_by[i] == n - 1:
                return i
        
        return -1
# Example usage:
solution = Solution()
n = 3
trust = [[1, 2], [2, 3]]
result = solution.FindJudge(n, trust)
print(result)  # Output: -1 (no judge in this case)