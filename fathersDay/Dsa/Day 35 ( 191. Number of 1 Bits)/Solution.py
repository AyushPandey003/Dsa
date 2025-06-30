class Solution:
    def NumberOfoneBits(self, n: int) -> int:
        count = 0
        while n:
            count += n & 1
            n >>= 1
        return count
# Example usage:
solution = Solution()
n = 11  # Binary representation: 1011
result = solution.NumberOfoneBits(n)
print(result)  # Output: 3 (there are three '1' bits in the