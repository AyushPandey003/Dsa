```markdown
# Contains Duplicate

This repository contains solutions to the "Contains Duplicate" problem from LeetCode. The problem asks to determine if any value appears at least twice in a given integer array.

## Problem Description

Given an integer array `nums`, return `true` if any value appears at least twice in the array, and return `false` if every element is distinct.

### Examples

```

Input: nums = \[1,2,3,1]
Output: true
Explanation: The element 1 occurs at the indices 0 and 3.

Input: nums = \[1,2,3,4]
Output: false
Explanation: All elements are distinct.

Input: nums = \[1,1,1,3,3,4,3,2,4,2]
Output: true
```
### Constraints

- `1 <= nums.length <= 10^5`
- `-10^9 <= nums[i] <= 10^9`
```

## Solutions

This repository provides solutions in three different programming languages: Python, C++, and Java.

---

### Python

```python
def solution(nums):
    seen = set()
    for num in nums:
        if num in seen:
            return True
        seen.add(num)
    return False

# Example usage:
k = solution([1, 2, 3, 1])
print(k)  # Output: True
```

**Explanation:**

This Python solution utilizes a `set` to efficiently check for duplicate elements. Sets only store unique elements. The code iterates through the input array `nums`, and for each `num`, it checks if it already exists in the `seen` set. If so, a duplicate is found and the function returns `True`. If the loop completes without finding any duplicates, the function returns `False`.

---

### C++

```cpp
#include <iostream>
#include <unordered_set>

using namespace std;

class Solution {
public:
    bool containsDuplicate(int* nums, int numsSize) {
        unordered_set<int> seen;
        for (int i = 0; i < numsSize; i++) {
            if (seen.count(nums[i])) {
                return true;
            }
            seen.insert(nums[i]);
        }
        return false;
    }
};

int main() {
    Solution sol;
    int nums1[] = {1, 2, 3, 1};
    int size1 = sizeof(nums1) / sizeof(nums1[0]);
    cout << (sol.containsDuplicate(nums1, size1) ? "Contains duplicate" : "No duplicates") << endl;

    int nums2[] = {1, 2, 3, 4};
    int size2 = sizeof(nums2) / sizeof(nums2[0]);
    cout << (sol.containsDuplicate(nums2, size2) ? "Contains duplicate" : "No duplicates") << endl;

    int nums3[] = {1, 1, 1, 3, 3, 4, 3, 2, 4, 2};
    int size3 = sizeof(nums3) / sizeof(nums3[0]);
    cout << (sol.containsDuplicate(nums3, size3) ? "Contains duplicate" : "No duplicates") << endl;

    return 0;
}
```

**Explanation:**

The C++ solution uses an `unordered_set` to track elements seen so far. For each element in the array, it checks if the element exists in the set using `seen.count()`. If it does, it returns `true`. Otherwise, the element is inserted. If no duplicates are found by the end, it returns `false`.

> 💡 **Note:** Avoid using fixed-size arrays like `int hashTable[100000] = {0};` due to the large range `-10^9 to 10^9`. This may cause memory issues and is not suitable here.

---

### Java

```java
import java.util.HashMap;
import java.util.Map;

public class ContainsDuplicate {
    public static class Solution {
        public boolean containsDuplicate(int[] nums) {
            Map<Integer, Integer> myCountArray = new HashMap<>();
            for (int i : nums) {
                if (myCountArray.containsKey(i)) {
                    return true;
                }
                myCountArray.put(i, 1);
            }
            return false;
        }
    }

    public static void main(String[] args) {
        Solution solution = new Solution();

        int[] nums1 = {1, 2, 3, 1};
        System.out.println(solution.containsDuplicate(nums1)); // Output: true

        int[] nums2 = {1, 2, 3, 4};
        System.out.println(solution.containsDuplicate(nums2)); // Output: false

        int[] nums3 = {1, 1, 1, 3, 3, 4, 3, 2, 4, 2};
        System.out.println(solution.containsDuplicate(nums3)); // Output: true
    }
}
```

**Explanation:**

The Java solution uses a `HashMap` to track occurrences. For each element, it checks if the key already exists in the map. If yes, a duplicate is found. Otherwise, it adds the element with a dummy value. The `HashMap` allows fast average-time lookups and insertions.

