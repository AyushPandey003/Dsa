class Solution:
    def arraySign(self, nums: list[int]) -> int:
        product = 1
        for num in nums:
            if num == 0:
                return 0
            elif num < 0:
                product *= -1
        return product
# Example usage
solution = Solution()
print(solution.arraySign([-1, -2, -3, -4, 3, 2, 1])) 
print(solution.arraySign([1, 5, 0, 2, -3]))  
print(solution.arraySign([-1, 1, -1, 1, -1]))  