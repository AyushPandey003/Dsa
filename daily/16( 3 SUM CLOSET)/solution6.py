class Solution:
    def min_additions_to_sort(arr):
        min_Element = float('inf')
        for i in range(len(arr)):
            if arr[i] < min_Element:
                min_Element = arr[i]
        for i in range(len(arr)):
            if arr[i] == 0:
                arr[i] = min_Element
        last_non_zero_index = 0
        for i in range(len(arr)):
            if arr[i] != 0:
                arr[last_non_zero_index] = arr[i]
                last_non_zero_index += 1
        return arr
k= Solution()
print(k.min_additions_to_sort([0, 1, 0, 3, 12]))  
