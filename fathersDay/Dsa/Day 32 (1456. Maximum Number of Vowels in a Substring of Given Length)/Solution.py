class Solution:
    def MaximumVowels(self, s: str, k: int) -> int:
        vowels = set('aeiou')
        max_vowels = 0
        current_vowels = 0
        for i in range(min(k, len(s))):
            if s[i] in vowels:
                current_vowels += 1
        
        max_vowels = current_vowels
        for i in range(k, len(s)):
            if s[i] in vowels:
                current_vowels += 1
            if s[i - k] in vowels:
                current_vowels -= 1
            
            max_vowels = max(max_vowels, current_vowels)
        
        return max_vowels
    
# Example usage:
solution = Solution()
s = "abciiidef"
k = 3
result = solution.MaximumVowels(s, k)
print(result)  # Output: 3