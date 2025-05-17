def solution(k, arr):
    index_map = {} 
    j = []  

    for idx, num in enumerate(arr):
        complement = k - num
        if complement in index_map:
            j.append(index_map[complement])
            j.append(idx)
        index_map[num] = idx  
    return j

y = solution(9, [2, 7, 11, 15])
print(y)