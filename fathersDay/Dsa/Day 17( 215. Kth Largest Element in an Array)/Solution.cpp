#include <vector>
#include <queue>
#include <functional> // For std::greater

class Solution {
public:
    int findKthLargest(std::vector<int>& nums, int k) {
        // Create a min-priority queue
        // std::priority_queue<int, std::vector<int>, std::greater<int>> minHeap;
        // The above line is correct, but for competitive programming,
        // it's common to use a lambda or a custom comparator if needed.
        // For a min-heap, std::greater<int> is the standard way.
        std::priority_queue<int, std::vector<int>, std::greater<int>> minHeap;

        for (int num : nums) {
            minHeap.push(num);
            if (minHeap.size() > k) {
                minHeap.pop(); // Remove the smallest element if heap size exceeds k
            }
        }

        return minHeap.top(); // The top of the min-heap is the k-th largest element
    }
};

// Example usage (for testing purposes, not part of the class)
/*
#include <iostream>
int main() {
    Solution sol;
    std::vector<int> nums = {3, 2, 1, 5, 6, 4};
    int k = 2;
    std::cout << "Kth largest element: " << sol.findKthLargest(nums, k) << std::endl; // Output: 5
    return 0;
}
*/
