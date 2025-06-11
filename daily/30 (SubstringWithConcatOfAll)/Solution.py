from typing import List
class Solution:
    def findSubstring(self, s: str, words: List[str]) -> List[int]:
        if not words:
            return []
        
        from collections import Counter
        word_length = len(words[0])
        total_length = len(words) * word_length
        word_count = Counter(words)
        result = []

        for i in range(len(s) - total_length + 1):
            seen = {}
            j = 0
            while j < len(words):
                word = s[i + j*word_length : i + (j+1)*word_length]
                if word in word_count:
                    seen[word] = seen.get(word, 0) + 1
                    if seen[word] > word_count[word]:
                        break
                else:
                    break
                j += 1
            if j == len(words):
                result.append(i)
        return result
sol=Solution()
k=sol.findSubstring("barfoothefoobarman",["foo","bar"])
print(k) 