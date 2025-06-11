from typing import List
class Solution:
    def threeSumClosest(self, nums: List[int], target: int) -> int:
        left=0
        right=len(nums)-1
        nums.sort()
        closest_sum = float('inf')
        for i in range(len(nums)-2):
            if i > 0 and nums[i] == nums[i-1]:
                continue
            left = i + 1
            right = len(nums) - 1
            while left < right:
                current_sum = nums[i] + nums[left] + nums[right]
                if abs(current_sum - target) < abs(closest_sum - target):
                    closest_sum = current_sum
                if current_sum < target:
                    left += 1
                elif current_sum > target:
                    right -= 1
                else:
                    return current_sum
                
        return closest_sum
sol=Solution()
k=sol.threeSumClosest([-1,2,1,-4],1)
print(k) 