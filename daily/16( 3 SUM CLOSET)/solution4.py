class Solution:
    def LongestHappyPrefix(self, s: str) -> int:
        n = len(s)
        if n == 0:
            return 0
        lps = [0] * n
        length = 0
        i = 1
        while i < n:
            if s[i] == s[length]:
                length += 1
                lps[i] = length
                i += 1
                print(lps)
            else:
                if length != 0:
                    length = lps[length - 1]
                    print(length)
                else:
                    lps[i] = 0
                    i += 1
                    print(lps)
        count = lps[-1]
        if count > 0:
            return s[:count]
        else:
            return ""
# Example usage
solution = Solution()
s = "ababab"
print(solution.LongestHappyPrefix(s))  #output l