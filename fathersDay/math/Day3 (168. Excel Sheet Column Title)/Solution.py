class Solution:
    def ExcelColumnTitle(self, n: int) -> str:
        result = []
        while n > 0:
            n -= 1
            remainder = n % 26
            result.append(chr(remainder + ord('A')))
            n //= 26
        return ''.join(reversed(result))
# Example usage
solution = Solution()
print(solution.ExcelColumnTitle(1)) 
