class Solution:
    def LongestSubstringWithoutRepeating(self, c: str) -> int:
        maxLen=0
        set1=set()
        left=0
        for right in range(len(c)):
            while c[right] in set1:
                set1.remove(c[left])
                left += 1
            set1.add(c[right])
            maxLen = max(maxLen, right - left + 1)
        return maxLen
    
# Example usage
solution = Solution()
s = "xyzxyzyy"
print(solution.LongestSubstringWithoutRepeating(s))  