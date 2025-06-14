class Solution:
    def ShortestPallindrome(self, s: str) -> str:
        if not s:
            return ""
        rev = s[::-1]
        for i in range(len(s)):
            if s.startswith(rev[i:]):
                return rev[:i] + s
        return ""
    
# Example usage
solution = Solution()
s = "racettt"
print(solution.ShortestPallindrome(s))  