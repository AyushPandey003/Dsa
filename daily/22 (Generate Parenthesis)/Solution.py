from typing import List
class Solution:
    def generateParenthesis(self, n: int) -> List[str]:
        if n == 0:
            return [""]
        result = []
        def backtrack(current: str, open_count: int, close_count: int):
            if open_count == n and close_count == n:
                result.append(current)
                return
            if open_count < n:
                backtrack(current + "(", open_count + 1, close_count)
            if close_count < open_count:
                backtrack(current + ")", open_count, close_count + 1)
        backtrack("", 0, 0)
        return result
k=Solution()
print(k.generateParenthesis(3))  
        