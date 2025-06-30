class Solution:
    def LengthOfLastWord(self, s: str) -> int:
        s = s.rstrip()
        if not s:
            return 0
        words = s.split(' ')
        return len(words[-1]) if words else 0
solution = Solution()
# Example usage:
s = "Hello World"
print(solution.LengthOfLastWord(s))  # Output: 5