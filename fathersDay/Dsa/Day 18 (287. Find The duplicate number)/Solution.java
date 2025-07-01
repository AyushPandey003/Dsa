class Solution {
    public int findDuplicate(int[] nums) {
        int slow = nums[0];
        int fast = nums[0];

        // Phase 1: Find the intersection point of the two pointers
        do {
            slow = nums[slow];
            fast = nums[nums[fast]];
        } while (slow != fast);

        // Phase 2: Find the entrance to the cycle
        slow = nums[0];
        while (slow != fast) {
            slow = nums[slow];
            fast = nums[fast];
        }

        return slow;
    }
}

/*
// Example usage:
public class Main {
    public static void main(String[] args) {
        Solution sol = new Solution();
        int[] nums = {3, 1, 3, 4, 2};
        System.out.println("The duplicate number is: " + sol.findDuplicate(nums)); // Expected: 3
    }
}
*/