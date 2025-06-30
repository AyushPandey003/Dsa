class Solution:
    def RemoveDuplicates(self, s: str) -> str:
        stack = []
        for char in s:
            if stack and stack[-1] == char:
                stack.pop()
            else:
                stack.append(char)
        return ''.join(stack)
solution = Solution()
s = "abbaca"
result = solution.RemoveDuplicates(s)
print(result)  # Output: "ca", as adjacent duplicates are removed