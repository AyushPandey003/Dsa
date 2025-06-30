from typing import List
class Solution:
    def firstMissingPositive(self, nums: List[int]) -> int:
        for i in range(len(nums)):
            while 1 <= nums[i] <= len(nums) and nums[nums[i] - 1] != nums[i]:
                nums[nums[i] - 1], nums[i] = nums[i], nums[nums[i] - 1]
        for i in range(len(nums)):
            if nums[i] != i + 1:
                return i + 1
        return len(nums) + 1
if __name__ == "__main__":
    solution = Solution()
    print(solution.firstMissingPositive([1, 2, 0]))
    print(solution.firstMissingPositive([3, 4, -1, 1]))  
    print(solution.firstMissingPositive([7, 8, 9, 11, 12]))  
    print(solution.firstMissingPositive([])) 
    print(solution.firstMissingPositive([7,8,9,11,12]))
    print(solution.firstMissingPositive([2]))  