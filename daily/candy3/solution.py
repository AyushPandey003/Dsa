from typing import List

class Solution:
    def candy(self, ratings: List[int]) -> int:
  
        n = len(ratings)
        if n == 0:
            return 0
        if n == 1:
            return 1
        neighbor = [1] * n
        for i in range(1, n):
            if ratings[i] > ratings[i - 1]:
                neighbor[i] = neighbor[i - 1] + 1
        for i in range(n - 2, -1, -1):
            if ratings[i] > ratings[i + 1]:
                neighbor[i] = max(neighbor[i], neighbor[i + 1] + 1)
        return sum(neighbor)
s= Solution()
k= [1,2,2]
print(s.candy(k))  
