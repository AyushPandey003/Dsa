class Solution:
    def RotateString(self, s: str, goal: str) -> bool:
        # Check if the lengths of both strings are equal
        if len(s) != len(goal):
            return False
        
        # Concatenate s with itself and check if goal is a substring
        doubled_s = s + s
        return goal in doubled_s    
# Example usage:
s = "abcde"
goal = "cdeab"
solution = Solution()
result = solution.RotateString(s, goal)