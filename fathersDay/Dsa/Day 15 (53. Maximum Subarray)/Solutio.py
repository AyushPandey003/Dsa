from typing import List
class Solution :
    def maxSubArray(self, nums: List[int]) -> int:
        """
        Find the contiguous subarray (containing at least one number) which has the largest sum and return its sum.
        """
        max_sum = current_sum = nums[0]
        
        for num in nums[1:]:
            current_sum = max(num, current_sum + num)
            max_sum = max(max_sum, current_sum)
        
        return max_sum
    
# Example usage:
nums= [-2,1,-3,4,-1,2,1,-5,4]
solution = Solution()
print(solution.maxSubArray(nums))  # Output: 6 (subarray [4,-1,2,1] has the largest sum)