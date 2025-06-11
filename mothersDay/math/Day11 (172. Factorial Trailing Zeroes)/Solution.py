class Solution:
    def FactorialTrailingZeroes(self, n):
        if n < 0:
            return 0
        
        count = 0
        while n >= 5:
            n //= 5
            count += n
        
        return count
# Example usage
k = Solution()
result = k.FactorialTrailingZeroes(25)
print(result)  # Output: 6