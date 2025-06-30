class Solution:
    def countSubarrays(self, nums: list[int], k: int) -> int:
        from math import gcd
        from collections import defaultdict
        
        n = len(nums)
        count = 0
        if k == 0:
            return 0
        
        for i in range(n):
            current_lcm = nums[i]
            if current_lcm > k:
                continue
            
            for j in range(i, n):
                current_lcm = (current_lcm * nums[j]) // gcd(current_lcm, nums[j])
                
                if current_lcm == k:
                    count += 1
                elif current_lcm > k:
                    break
        
        return count
    
# Example usage:
solution = Solution()
nums = [3, 6, 2, 7, 1]
k = 6
print(solution.countSubarrays(nums, k))  # Output: 4