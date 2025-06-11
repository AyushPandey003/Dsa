class Solution:
    def ValidPerfectSquare(self, num: int) -> bool:
        if num < 0:
            return False
        left, right = 0, num
        while left <= right:
            mid = (left + right) // 2
            square = mid * mid
            if square == num:
                return True
            elif square < num:
                left = mid + 1
            else:
                right = mid - 1
        return False
k = Solution()
result = k.ValidPerfectSquare(16)
print(result)  # Output: True