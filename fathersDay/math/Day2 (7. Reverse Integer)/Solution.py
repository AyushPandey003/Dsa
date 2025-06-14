class Solution:
    def Reverse(self, x: int) -> int:
        sign = -1 if x < 0 else 1
        x = abs(x)
        reversed_x = 0
        
        while x > 0:
            digit = x % 10
            reversed_x = reversed_x * 10 + digit
            x //= 10
            
        reversed_x *= sign
        if reversed_x < -2**31 or reversed_x > 2**31 - 1:
            return 0
        
        return reversed_x

solution = Solution()
print(solution.Reverse(123))        
print(solution.Reverse(-123))      
print(solution.Reverse(120))       
