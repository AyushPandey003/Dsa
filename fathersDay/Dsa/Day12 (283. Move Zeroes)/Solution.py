class Solution:
    def MoveZeroes(self, nums: list[int]) -> None:
        last_non_zero_index = 0
        
        for i in range(len(nums)):
            if nums[i] != 0:
                nums[last_non_zero_index] = nums[i]
                last_non_zero_index += 1
        
        for i in range(last_non_zero_index, len(nums)):
            nums[i] = 0
#        