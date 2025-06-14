class Solution:
    def minimumRemoveToMakeValid(self, s: str) -> str:
        result = []
        balance = 0
        for char in s:
            if char == '(':
                balance += 1
                result.append(char)
            elif char == ')':
                if balance > 0:
                    balance -= 1
                    result.append(char)
            else:
                result.append(char)
        final_result = []
        balance = 0
        for char in reversed(result):
            if char == '(':
                if balance > 0:
                    balance -= 1
                    final_result.append(char)
            elif char == ')':
                balance += 1
                final_result.append(char)
            else:
                final_result.append(char)
        return ''.join(reversed(final_result))