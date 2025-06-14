class Solution:
    def BasicCalculator(self, s: str) -> int:
        def calculate(s):
            stack = []
            num = 0
            sign = 1
            res = 0
            i = 0
            while i < len(s):
                char = s[i]
                if char.isdigit():
                    num = num * 10 + int(char)
                elif char == '+':
                    res += sign * num
                    num = 0
                    sign = 1
                elif char == '-':
                    res += sign * num
                    num = 0
                    sign = -1
                elif char == '(':
                    stack.append(res)
                    stack.append(sign)
                    res = 0
                    sign = 1
                elif char == ')':
                    res += sign * num
                    num = 0
                    res *= stack.pop()
                    res += stack.pop()
                i += 1
            res += sign * num
            return res

        return calculate(s.replace(' ', ''))