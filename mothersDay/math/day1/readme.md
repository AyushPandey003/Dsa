

```markdown
# Missing Number

## Problem Statement
Given an array `nums` containing `n` distinct numbers in the range `[0, n]`, return the only number in the range that is missing from the array.

### Example 1:
**Input:** 
```plaintext
nums = [3,0,1]
```
**Output:** 
```plaintext
2
```
**Explanation:**  
Since `n = 3`, all numbers should be in the range `[0,3]`. The number `2` is missing.

### Example 2:
**Input:** 
```plaintext
nums = [0,1]
```
**Output:** 
```plaintext
2
```
**Explanation:**  
Since `n = 2`, the range is `[0,2]`, and the missing number is `2`.

### Example 3:
**Input:** 
```plaintext
nums = [9,6,4,2,3,5,7,0,1]
```
**Output:** 
```plaintext
8
```
**Explanation:**  
Since `n = 9`, all numbers should be in the range `[0,9]`, and `8` is the missing number.

## Constraints
- `n == nums.length`
- `1 <= n <= 10⁴`
- `0 <= nums[i] <= n`
- All elements in `nums` are unique.

## Optimal Solution

### Approach 1: Using Sum Formula (O(n) time, O(1) space)
We can use the **sum formula** for the first `n` natural numbers:

\[
\text{expectedSum} = \frac{n(n+1)}{2}
\]

Then, subtract the sum of the given numbers from `expectedSum`:

```python
def missingNumber(nums):
    n = len(nums)
    expected_sum = n * (n + 1) // 2
    actual_sum = sum(nums)
    return expected_sum - actual_sum
```

### Approach 2: Using XOR (O(n) time, O(1) space)
Since `a ⊕ a = 0` and `a ⊕ 0 = a`, we can XOR all numbers in `[0,n]` with all elements in `nums`, canceling out existing numbers and leaving only the missing number:

```python
def missingNumber(nums):
    missing = len(nums)
    for i, num in enumerate(nums):
        missing ^= i ^ num
    return missing
```

## Follow-Up Question
Can you come up with another approach that maintains **O(1) space complexity and O(n) runtime complexity**?

---

