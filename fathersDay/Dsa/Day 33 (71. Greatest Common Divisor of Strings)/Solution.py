class Solution:
    def GreatestCommonDivisor(self, str1: str, str2: str) -> str:
        import math
        if str1 + str2 != str2 + str1:
            return ""
        gcd_len = math.gcd(len(str1), len(str2))
        return str1[:gcd_len]
# Example usage:
solution = Solution()
str1 = "ABCABC"
str2 = "ABC"
result = solution.GreatestCommonDivisor(str1, str2)
print(result)  # Output: "ABC"