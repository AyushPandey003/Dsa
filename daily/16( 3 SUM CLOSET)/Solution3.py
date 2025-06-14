class Solution:
    # def LongestPallindromicSubstring(self, s: str) -> str:
    #     n = len(s)
    #     if n == 0:
    #         return ""
    #     start, max_len = 0, 1

    #     def expand_around_center(left, right):
    #         while left >= 0 and right < n and s[left] == s[right]:
    #             left -= 1
    #             right += 1
    #         return left + 1, right - 1

    #     for i in range(n):
    #         l1, r1 = expand_around_center(i, i)
    #         l2, r2 = expand_around_center(i, i + 1)
    #         if r1 - l1 + 1 > max_len:
    #             start, max_len = l1, r1 - l1 + 1
    #         if r2 - l2 + 1 > max_len:
    #             start, max_len = l2, r2 - l2 + 1

    #     return s[start:start + max_len]
    def LongestPallindromicSubstring(self,s: str) -> str:
        t = '#' + '#'.join(s) + '#'
        print(t)
        n = len(t)
        p = [0] * n
        print(p)
        center, right = 0, 0

        for i in range(n):
            mirror = 2 * center - i
            if i < right:
                p[i] = min(right - i, p[mirror])
            while i + p[i] + 1 < n and i - p[i] - 1 >= 0 and t[i + p[i] + 1] == t[i - p[i] - 1]:
                p[i] += 1
            if i + p[i] > right:
                center, right = i, i + p[i]
        max_len, start = max((p[i], i) for i in range(n))
        return s[(start - max_len) // 2: (start + max_len) // 2]

solution = Solution()
s = "babad"
print(solution.LongestPallindromicSubstring(s))  
