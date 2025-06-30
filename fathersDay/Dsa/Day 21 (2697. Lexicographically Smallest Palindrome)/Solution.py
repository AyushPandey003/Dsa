class Solution:
    def makeSmallestPalindrome(self, s: str) -> str:
        s = list(s)
        left, right = 0, len(s) - 1
        while left < right:
            if s[left] != s[right]:
                smaller = min(s[left], s[right])
                s[left] = s[right] = smaller
            left += 1
            right -= 1
        return ''.join(s)
solution = Solution()
# Example usage:
s = "egcfe"
print(solution.makeSmallestPalindrome(s))  # Output: "efcfe"