class Solution:
    def Day10BulbSwitcher(self, n):
        if n < 1:
            return 0
        return int(n**0.5)
# Example usage
k = Solution()
result = k.Day10BulbSwitcher(3)
print(result)  # Output: 1