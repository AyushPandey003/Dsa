class Solution:
    def ValidParenthesisString(self, s: str) -> bool:
        left_balance = 0
        right_balance = 0
        
        for char in s:
            if char == '(' or char == '*':
                left_balance += 1
            else:
                left_balance -= 1
            
            if left_balance < 0:
                return False
        
        for char in reversed(s):
            if char == ')' or char == '*':
                right_balance += 1
            else:
                right_balance -= 1
            
            if right_balance < 0:
                return False
        
        return True
# Example usage:
solution = Solution()
print(solution.ValidParenthesisString("(*)"))  # Output: True