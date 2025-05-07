def solution(nums):
    seen=set();
    for num in nums:
        if num in seen:
            return True
        seen.add(num)
    return False
k=solution([1,2,3,1])
print(k) 