class Solution:
    def PlusOne(self, digits):
        carry = 1
        for i in range(len(digits) - 1, -1, -1):
            if carry == 0:
                break
            digits[i] += carry
            if digits[i] == 10:
                digits[i] = 0
                carry = 1
            else:
                carry = 0
        if carry == 1:
            digits.insert(0, 1)
        return digits
# Example usage
k= Solution()
result = k.PlusOne([1, 2, 3])
print(result)  