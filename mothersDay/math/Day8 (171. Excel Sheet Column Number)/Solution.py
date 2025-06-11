class Solution:
    def ExcelColumnNumber(self, s):
        result = 0
        for char in s:
            result = result * 26 + (ord(char) - ord('A') + 1)
        return result
# Example usage
k = Solution()
result = k.ExcelColumnNumber("AB")
print(result)  # Output: 28