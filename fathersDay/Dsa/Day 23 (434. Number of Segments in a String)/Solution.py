class Solution:
    def NumberOfSegments(self, s: str) -> int:
        segments = s.split()
        return len(segments)
solution=Solution()
# Example usage:
s = "Hello, my name is John"
result = solution.NumberOfSegments(s)
print(result)  # Output: 5, as there are five segments in the string