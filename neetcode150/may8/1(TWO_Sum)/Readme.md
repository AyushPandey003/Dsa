---

This repository contains efficient solutions to the classic **Two Sum** algorithm in **Python**, **Java**, and **C++** using a **hash map** for optimal performance.

---

## 🧠 Problem Statement

> Given an array of integers `nums` and an integer `target`, return the indices of the two numbers such that they add up to the target.

* Each input has **exactly one solution**.
* You **may not use the same element twice**.
* Return the result as **0-based indices**.

---

## 💡 Algorithm Explanation

We use a **hash map** (or `unordered_map` in C++) to store previously seen numbers and their indices.

### Why a hash map?

Because it allows **constant-time lookups**, making the overall algorithm run in **linear time**.

### Steps:

1. Iterate through each number in the array.
2. Compute its **complement**: `target - current_number`.
3. If the complement is already in the map, return its index and the current index.
4. If not, store the current number and its index in the map.

---

## 📁 Project Structure

```
├── two_sum.py        # Python implementation
├── TwoSum.java       # Java implementation
├── two_sum.cpp       # C++ implementation
└── README.md         # Documentation (you are here)
```

---

## 🐍 Python Code

**File:** `two_sum.py`

```python
def solution(k, arr):
    index_map = {} 
    for idx, num in enumerate(arr):
        complement = k - num
        if complement in index_map:
            return [index_map[complement], idx]
        index_map[num] = idx  
    raise ValueError("No two sum solution")

# Example
y = solution(9, [2, 7, 11, 15])
print("Indices:", y)
```

---

## ☕ Java Code

**File:** `TwoSum.java`

```java
import java.util.HashMap;

class Solution {
    public int[] twoSum(int[] nums, int target) {
        HashMap<Integer, Integer> map = new HashMap<>();
        for (int i = 0; i < nums.length; i++) {
            int complement = target - nums[i];
            if (map.containsKey(complement)) {
                return new int[] { map.get(complement), i };
            }
            map.put(nums[i], i);
        }
        throw new IllegalArgumentException("No two sum solution");
    }

    public static void main(String[] args) {
        Solution solution = new Solution();
        int[] nums = {2, 7, 11, 15};
        int target = 9;
        int[] result = solution.twoSum(nums, target);
        System.out.println("Indices: " + result[0] + ", " + result[1]);
    }
}
```

---

## 💻 C++ Code

**File:** `two_sum.cpp`

```cpp
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int, int> num_map;
    for (int i = 0; i < nums.size(); i++) {
        int complement = target - nums[i];
        if (num_map.find(complement) != num_map.end()) {
            return {num_map[complement], i};
        }
        num_map[nums[i]] = i;
    }
    throw runtime_error("No two sum solution");
}

int main() {
    vector<int> nums = {2, 7, 11, 15};
    int target = 9;
    vector<int> result = twoSum(nums, target);
    cout << "Indices: " << result[0] << ", " << result[1] << endl;
    return 0;
}
```

---

## 🧪 Sample Input/Output

**Input:**

```text
nums = [2, 7, 11, 15]
target = 9
```

**Output:**

```text
Indices: 0, 1
```

Explanation: `nums[0] + nums[1] = 2 + 7 = 9`

---

## ✅ Time and Space Complexity

| Language | Approach       | Time Complexity | Space Complexity | Notes                       |
| -------- | -------------- | --------------- | ---------------- | --------------------------- |
| Python   | Hash Map       | O(n)            | O(n)             | Fast dictionary lookup      |
| Java     | HashMap        | O(n)            | O(n)             | Constant-time map ops       |
| C++      | unordered\_map | O(n)            | O(n)             | Best case avg constant time |

---

## 📜 License

This project is licensed under the [MIT License](https://opensource.org/licenses/MIT). Feel free to use or modify it in your own work.

---

Let me know if you'd like me to export this as a downloadable `README.md` file.
