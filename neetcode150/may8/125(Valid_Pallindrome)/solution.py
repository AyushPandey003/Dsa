def Solution(s):
   # "A man, a plan, a canal: Panama"
   filteredS = s.lower()
   filteredS = ''.join(c for c in filteredS if c.isalnum())
   if filteredS == filteredS[::-1]:
      return True
   return False

s = "A man, a plan, a canal: Panama"
k = Solution(s)
print(k)  # Output: True
