class Solution:
    def FindFirstPalindromic(self, words: list[str]) -> str:
        for word in words:
            if word == word[::-1]:
                return word
        return ""
solution = Solution()
# Example usage:
words = ["racecar", "hello", "level"]
result = solution.FindFirstPalindromic(words)
print(result)  # Output: "racecar", as it is the first palindromic string in the array