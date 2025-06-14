import sys

class Solution:
    def maxDifference(self, s: str, k: int) -> int:
        def getStatus(cnt_a, cnt_b):
            return ((cnt_a & 1) << 1) | (cnt_b & 1)

        n = len(s)
        ans = -sys.maxsize
        for a in map(str, range(5)):
            for b in map(str, range(5)):
                if a == b:
                    continue
                best = [sys.maxsize] * 4
                cnt_a = cnt_b = prev_a = prev_b = 0
                left = -1
                for right in range(n):
                    cnt_a += (s[right] == a)
                    cnt_b += (s[right] == b)
                    while right - left >= k and cnt_b - prev_b >= 2:
                        left_status = getStatus(prev_a, prev_b)
                        best[left_status] = min(best[left_status], prev_a - prev_b)
                        left += 1
                        prev_a += (s[left] == a)
                        prev_b += (s[left] == b)
                    right_status = getStatus(cnt_a, cnt_b)
                    if best[right_status ^ 0b10] != sys.maxsize:
                        ans = max(ans, cnt_a - cnt_b - best[right_status ^ 0b10])
        return ans
solution = Solution()
print(solution.maxDifference("1122211", 3))  
print(solution.maxDifference("12233", 4))
print(solution.maxDifference("110", 3))