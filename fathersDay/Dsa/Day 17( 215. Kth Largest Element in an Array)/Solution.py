import random
import heapq

class Solution:
    def kthLargest(self, nums: list[int], k: int) -> int:
        return heapq.nlargest(k, nums)[-1]
solution = Solution()
nums = [3, 2, 1, 5, 6, 4]
k = 2
print(solution.kthLargest(nums, k))  # Output: 5