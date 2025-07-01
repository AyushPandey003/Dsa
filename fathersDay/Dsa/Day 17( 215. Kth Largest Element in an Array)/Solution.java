import java.util.PriorityQueue;

class Solution {
    public int findKthLargest(int[] nums, int k) {
        // Create a min-priority queue
        PriorityQueue<Integer> minHeap = new PriorityQueue<>();

        for (int num : nums) {
            minHeap.offer(num); // Add element to the heap
            if (minHeap.size() > k) {
                minHeap.poll(); // Remove the smallest element if heap size exceeds k
            }
        }

        return minHeap.peek(); // The top of the min-heap is the k-th largest element
    }
}

// Example usage (for testing purposes, not part of the class)
/*
public class Main {
    public static void main(String[] args) {
        Solution sol = new Solution();
        int[] nums = {3, 2, 1, 5, 6, 4};
        int k = 2;
        System.out.println("Kth largest element: " + sol.findKthLargest(nums, k)); // Output: 5
    }
}
*/
