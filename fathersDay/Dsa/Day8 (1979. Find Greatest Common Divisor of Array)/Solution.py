from math import gcd

class Solution:
    def FindGCD(self, nums: list[int]) -> int:
        return gcd(min(nums), max(nums))
    
# Example usage
solution = Solution()
arr = [2, 5, 6, 9, 10]
print(solution.FindGCD(arr))  # Output: 2