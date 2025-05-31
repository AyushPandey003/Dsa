
from typing import List

class Solution:
    def missingNumber(self, nums: List[int]) -> int:
        nums.sort()
        print(nums)
        for i in range(len(nums)):
            if(nums[i]!=i):
                return i
            
sol = Solution()
k = sol.missingNumber([3,0,1])
print(k)
            