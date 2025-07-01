class Solution {
    public int majorityElement(int[] nums) {
        int count = 0;
        int candidate = 0;
        
        for (int num : nums) {
            if (count == 0) {
                candidate = num;
            }
            if (num == candidate) {
                count++;
            } else {
                count--;
            }
        }
        
        return candidate;
    }
}

// Example usage (for testing purposes, not part of the class)
/*
public class Main {
    public static void main(String[] args) {
        Solution sol = new Solution();
        int[] nums1 = {3, 2, 3};
        System.out.println("Majority Element: " + sol.majorityElement(nums1)); // Output: 3

        int[] nums2 = {2, 2, 1, 1, 1, 2, 2};
        System.out.println("Majority Element: " + sol.majorityElement(nums2)); // Output: 2
    }
}
*/
