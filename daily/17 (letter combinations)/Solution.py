from typing import List
class Solution:
    def letterCombinations(self, digits: str) -> List[str]:
        dic1={1:[""],2:['a','b','c'],3:['d','e','f'],4:['g','h','i'],5:['j','k','l'],6:['m','n','o'],7:['p','q','r','s'],8:['t','u','v'],9:['w','x','y','z']}
        result=[]
        if not digits:
            return []
        def backtrack(index, path):
            if index == len(digits):
                result.append(path)
                return
            digit = int(digits[index])
            for letter in dic1[digit]:
                backtrack(index + 1, path + letter)
        backtrack(0, "")
        return result
    
        