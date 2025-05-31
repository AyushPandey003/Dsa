def solution(arr):
    arr.sort() 
    result = []
    n = len(arr)
    
    for i in range(n):
        if i > 0 and arr[i] == arr[i - 1]:  
            continue
        
        left, right = i + 1, n - 1  
        
        while left < right:
            total = arr[i] + arr[left] + arr[right]
            
            if total == 0:
                result.append([arr[i], arr[left], arr[right]])
                
                while left < right and arr[left] == arr[left + 1]:
                    left += 1
                while left < right and arr[right] == arr[right - 1]:
                    right -= 1
                
                left += 1
                right -= 1
                
            elif total < 0:
                left += 1 
            else:
                right -= 1  
    
    return result