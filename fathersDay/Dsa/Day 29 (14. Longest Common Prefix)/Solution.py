class Solution:
    def LongestCommonPrefix(self, strs: list[str]) -> str:
        if not strs:
            return ""
        prefix = strs[0]
        for s in strs[1:]:
            while not s.startswith(prefix):
                prefix = prefix[:-1]
                if not prefix:
                    return ""
        return prefix
# Example usage:
solution = Solution()
strs = ["flower", "flow", "flight"]
result = solution.LongestCommonPrefix(strs)
print(result)  # Output: "fl", as it is the longest common prefix among the strings