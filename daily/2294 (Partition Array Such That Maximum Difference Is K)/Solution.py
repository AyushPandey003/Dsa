class Solution:
    def partitionArray(self, nums: List[int], k: int) -> int:
        nums.sort()
        count = 0
        i = 0
        while i < len(nums):
            count += 1
            j = i + 1
            while j < len(nums) and nums[j] - nums[i] <= k:
                j += 1
            i = j
        return count
from typing import List
if __name__ == "__main__":
    solution = Solution()
    print(solution.partitionArray([3, 6, 1, 2, 5], 2))  
    print(solution.partitionArray([1, 2, 3], 1))         
    print(solution.partitionArray([1, 3, 6, 7, 9], 3))  
    print(solution.partitionArray([10, 20, 30], 5))     
    print(solution.partitionArray([], 5))                