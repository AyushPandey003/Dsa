class Solution:
    def PrimeSetBits(self, left: int, right: int) -> int:
        def is_prime(n):
            if n < 2:
                return False
            for i in range(2, int(n**0.5) + 1):
                if n % i == 0:
                    return False
            return True
        
        count = 0
        for num in range(left, right + 1):
            set_bits = bin(num).count('1')
            if is_prime(set_bits):
                count += 1
        
        return count
# Example usage:
solution = Solution()
left = 6
right = 10
result = solution.PrimeSetBits(left, right)
print(result)  # Output: 4 (6, 7, 8, 9 have prime number of set bits)