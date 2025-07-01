# Kth Largest Element in an Array

## Problem Description
Given an integer array `nums` and an integer `k`, return the `k`th largest element in the array.

Note that it is the `k`th largest element in the sorted order, not the `k`th distinct element.

## Main Concepts

This problem can be solved using several approaches, each with its own time and space complexity trade-offs.

1.  **Sorting:** The most straightforward approach is to sort the array and then pick the `k`th element from the end (or `n-k`th element from the beginning, where `n` is the array size).
    *   **Time Complexity:** O(N log N) due to sorting.
    *   **Space Complexity:** O(1) or O(log N) depending on the sorting algorithm used (in-place or not).

2.  **Min-Heap (Priority Queue):** This is an efficient approach, especially when `k` is much smaller than `N`.
    *   Maintain a min-heap of size `k`. Iterate through the array:
        *   Add the current element to the heap.
        *   If the heap size exceeds `k`, remove the smallest element (heap's root).
    *   After processing all elements, the root of the min-heap will be the `k`th largest element.
    *   **Time Complexity:** O(N log k). Each insertion/deletion into a heap of size `k` takes O(log k) time, and we do this `N` times.
    *   **Space Complexity:** O(k) to store the heap.

3.  **QuickSelect (Partition-based Selection):** This is an average-case O(N) solution, similar to the partitioning step in QuickSort.
    *   The idea is to partition the array around a pivot such that elements smaller than the pivot are on one side and larger elements are on the other.
    *   If the pivot's position is `N-k`, then the pivot is the `k`th largest element.
    *   If the pivot's position is less than `N-k`, we search in the right partition.
    *   If the pivot's position is greater than `N-k`, we search in the left partition.
    *   **Time Complexity:** Average O(N), Worst-case O(N^2) (can be mitigated with a good pivot selection strategy).
    *   **Space Complexity:** O(log N) for recursion stack (average), O(N) (worst-case).

## Intuition (Min-Heap Approach)

The min-heap approach is intuitive because we only care about the `k` largest elements. By maintaining a min-heap of size `k`, we ensure that at any point, the heap contains the `k` largest elements encountered so far. The smallest element in this heap (its root) is the `k`th largest among those `k` elements. When we encounter a new number:

*   If it's larger than the smallest element in our heap (or if the heap is not yet full), it means this new number *could* be one of the `k` largest. So, we add it.
*   If adding it makes the heap size greater than `k`, it means we now have `k+1` candidates for the `k` largest. We then remove the smallest among them (which is the heap's root), ensuring the heap always holds the `k` largest elements seen so far.

After iterating through all numbers, the smallest element remaining in the heap (its root) will be the overall `k`th largest element.

## Pro Tips and Tricks

*   **Choose the Right Tool:** For competitive programming, `heapq.nlargest` in Python is a very concise way to implement the min-heap logic. In C++ and Java, `std::priority_queue` and `java.util.PriorityQueue` are your go-to.
*   **Min-Heap for Kth Largest:** Remember that to find the `k`th largest element, you use a *min-heap* of size `k`. Conversely, for the `k`th smallest, you'd use a *max-heap* of size `k`.
*   **QuickSelect Optimization:** While QuickSelect has a better average time complexity, its worst-case can be problematic. For interviews, understanding the concept is key. For practical implementations, the heap approach is often safer and easier to implement correctly.
*   **Edge Cases:** Consider edge cases like `k=1` (finding the maximum), `k=N` (finding the minimum), or an array with duplicate elements. The heap approach handles duplicates naturally.
*   **Python's `heapq` module:** `heapq.nlargest(k, iterable)` directly returns a list of the `k` largest elements. To get the `k`th largest, you simply take the last element of this list `[-1]`. This is a very Pythonic and efficient way to solve it.

## Example (Min-Heap)

Let `nums = [3, 2, 1, 5, 6, 4]` and `k = 2`.

1.  Initialize `minHeap`.
2.  `num = 3`: `minHeap = [3]`
3.  `num = 2`: `minHeap = [2, 3]`
4.  `num = 1`: `minHeap = [1, 2, 3]` (size > k=2, pop 1) -> `minHeap = [2, 3]`
5.  `num = 5`: `minHeap = [2, 3, 5]` (size > k=2, pop 2) -> `minHeap = [3, 5]`
6.  `num = 6`: `minHeap = [3, 5, 6]` (size > k=2, pop 3) -> `minHeap = [5, 6]`
7.  `num = 4`: `minHeap = [4, 5, 6]` (size > k=2, pop 4) -> `minHeap = [5, 6]`

After iterating through all numbers, the `minHeap` contains `[5, 6]`. The smallest element in the heap (its top) is `5`, which is the 2nd largest element.
