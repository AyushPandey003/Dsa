class Solution:
    def CountOdds(self, low: int, high: int) -> int:
        if low > high:
            return 0
        if low % 2 == 0:
            low += 1
        if high % 2 == 0:
            high -= 1
        return (high - low) // 2 + 1
# Example usage
k = Solution()
result = k.CountOdds(3, 7)
print(result)  