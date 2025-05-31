def solution(strs):
    result = {}
    for s in strs :
        sorted_s = ''.join(sorted(s))
        if sorted_s not in result :
            result[sorted_s] = []
        result[sorted_s].append(s)
    return list(result.values())
    
strs=["eat", "tea", "tan", "ate", "nat", "bat"]
print(solution(strs))
