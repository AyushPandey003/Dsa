class Solution:
    def checkPerfectNumber(self, num: int) -> bool:
        if num <= 1:
            return False
        
        total = 1  
        sqrt_num = int(num**0.5)
        
        for i in range(2, sqrt_num + 1):
            if num % i == 0:
                total += i
                if i != num // i:
                    total += num // i 
            
        return total == num