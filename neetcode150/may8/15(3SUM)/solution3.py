# my approach
# def solution(arr):
#     result = set() 
#     n = len(arr)
    
#     for i in range(n):
#         seen = set()
#         for j in range(i + 1, n):
#             k = -(arr[i] + arr[j]) 
#             if k in seen:
#                 result.add(tuple(sorted((arr[i], arr[j], k)))) 
#             seen.add(arr[j]) 
        
#     return [list(triplet) for triplet in result] 
# print(solution([-1, 0, 1, 2, -1, -4]))


# after deep analysis Best approach

def solution(nums, target, k):
    def two_sum(nums, target):
        res = []
        left, right = 0, len(nums) - 1
        while left < right:
            s = nums[left] + nums[right]
            if s == target:
                res.append([nums[left], nums[right]])
                left += 1
                right -= 1
                while left < right and nums[left] == nums[left - 1]:
                    left += 1  # Skip duplicates
                while left < right and nums[right] == nums[right + 1]:
                    right -= 1  # Skip duplicates
            elif s < target:
                left += 1
            else:
                right -= 1
        return res

    def k_sum_recursive(nums, target, k):
        res = []
        if not nums or nums[0] * k > target or nums[-1] * k < target:
            return res  # Early termination
        if k == 2:
            return two_sum(nums, target)

        for i in range(len(nums)):
            if i == 0 or nums[i] != nums[i - 1]:  # Skip duplicates
                for subset in k_sum_recursive(nums[i + 1:], target - nums[i], k - 1):
                    res.append([nums[i]] + subset)
        return res

    nums.sort()
    return k_sum_recursive(nums, target, k)

from dis import dis

print(dis(solution))


