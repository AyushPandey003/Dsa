from typing import List
class Solution:
    def rotate(self, nums: List[int], k: int) -> None:
        """
        Rotate the array nums to the right by k steps.
        This function modifies nums in-place.
        """
        n = len(nums)
        k %= n
        if k == 0:
            return
        nums.reverse()
        nums[:k] = reversed(nums[:k])
        nums[k:] = reversed(nums[k:])
        
    
    
# Example usage:
nums = [1, 2, 3, 4, 5, 6, 7]
k = 3
solution = Solution()
solution.rotate(nums, k)
print(nums)  # Output: [5, 6, 7, 1, 2, 3, 4]
