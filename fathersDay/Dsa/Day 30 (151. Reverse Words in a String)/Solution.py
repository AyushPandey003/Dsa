class Solution:
    def ReverseWords(self, s: str) -> str:
        words = s.split()
        reversed_words = words[::-1]
        # Join the reversed words with a single space
        return ' '.join(reversed_words)
    
solution= Solution()
words = "the sky is blue"
result = solution.ReverseWords(words)
print(result)  # Output: "blue is sky the"