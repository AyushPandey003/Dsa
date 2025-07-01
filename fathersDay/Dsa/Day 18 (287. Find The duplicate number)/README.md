# Find The Duplicate Number

## Intuition

The problem states that we have an array `nums` containing `n + 1` integers where each integer is between 1 and `n` (inclusive). This implies that there must be at least one duplicate number. The key insight to solving this problem efficiently is to view the array as a linked list where each index `i` points to the value `nums[i]`. Since the numbers are within the range `[1, n]` and there are `n+1` numbers, if we start traversing from `nums[0]`, we are guaranteed to eventually enter a cycle. The duplicate number is precisely the entry point of this cycle.

This transformation allows us to apply **Floyd's Cycle-Finding Algorithm** (also known as the "tortoise and hare" algorithm), which is typically used for linked lists, to find the duplicate number.

## Main Concept

**Floyd's Cycle-Finding Algorithm:** This algorithm is used to detect a cycle in a sequence and find the starting point of that cycle. It involves two phases:

1.  **Phase 1: Detect Cycle and Find Intersection Point:**
    *   Initialize two pointers, `slow` and `fast`, both starting at `nums[0]`.
    *   Move `slow` one step at a time (`slow = nums[slow]`).
    *   Move `fast` two steps at a time (`fast = nums[nums[fast]]`).
    *   If a cycle exists, `slow` and `fast` are guaranteed to meet at some point within the cycle.

2.  **Phase 2: Find Cycle Entrance (the Duplicate Number):**
    *   Once `slow` and `fast` meet, reset `slow` back to `nums[0]`.
    *   Keep `fast` at the intersection point found in Phase 1.
    *   Move both `slow` and `fast` one step at a time (`slow = nums[slow]`, `fast = nums[fast]`).
    *   The point where they meet again will be the entrance of the cycle, which is the duplicate number.

## Pro Tip and Trick

*   **Constraints are Key:** The problem's constraints (numbers from 1 to `n` in an array of size `n+1`) are fundamental. They ensure that a cycle *must* exist and that the values can be used as valid indices, effectively turning the array into a linked list structure.
*   **In-Place and O(1) Space:** This algorithm is highly efficient as it solves the problem without modifying the input array and uses only constant extra space (O(1)), which is often a critical requirement in competitive programming and real-world scenarios.
*   **Understanding the Cycle:** Imagine the array elements as nodes and the values as pointers. For example, if `nums = [1, 3, 4, 2, 2]`, then `0 -> 1 -> 3 -> 2 -> 4 -> 2` (a cycle `2 -> 4 -> 2` exists, and `2` is the entry point/duplicate).

## Algorithm Steps

1.  Initialize two integer pointers, `slow` and `fast`, both to `nums[0]`.
2.  **Phase 1 (Finding the intersection point):**
    *   Enter a `do-while` loop (or `while True` with a `break` condition).
    *   Update `slow = nums[slow]`.
    *   Update `fast = nums[nums[fast]]`.
    *   Break the loop when `slow == fast`.
3.  **Phase 2 (Finding the cycle entrance):**
    *   Reset `slow` to `nums[0]`.
    *   Enter a `while` loop that continues as long as `slow != fast`.
    *   Update `slow = nums[slow]`.
    *   Update `fast = nums[fast]`.
4.  Once the loop terminates (i.e., `slow == fast`), return `slow` (or `fast`), as this is the duplicate number.
