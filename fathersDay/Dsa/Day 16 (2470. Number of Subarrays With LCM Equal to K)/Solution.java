class Solution {

    // Helper function for GCD
    private long calculateGcd(long a, long b) {
        while (b != 0) {
            long temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }

    // Helper function for LCM, handling potential overflow
    private long calculateLcm(long a, long b) {
        if (a == 0 || b == 0) return 0;
        // To prevent overflow: lcm(a, b) = (a / gcd(a, b)) * b
        // Or, if a * b is guaranteed not to overflow, (a * b) / gcd(a, b)
        // Use long to handle potentially large intermediate LCM values.
        return (a / calculateGcd(a, b)) * b;
    }

    public int subarrayLCM(int[] nums, int k) {
        int n = nums.length;
        int count = 0;

        if (k == 0) {
            return 0;
        }

        for (int i = 0; i < n; ++i) {
            long current_lcm = nums[i]; // Use long to prevent overflow

            // If the first element itself is greater than k, no subarray starting here can have LCM = k
            if (current_lcm > k) {
                continue;
            }

            for (int j = i; j < n; ++j) {
                // Calculate LCM iteratively
                current_lcm = calculateLcm(current_lcm, nums[j]);

                if (current_lcm == k) {
                    count++;
                } else if (current_lcm > k) {
                    // If LCM exceeds k, it will only grow or stay the same, so break
                    break;
                }
            }
        }

        return count;
    }
}

// Example usage (for testing purposes, not part of the class)
/*
public class Main {
    public static void main(String[] args) {
        Solution sol = new Solution();
        int[] nums = {3, 6, 2, 7, 1};
        int k = 6;
        System.out.println("Number of subarrays with LCM equal to k: " + sol.subarrayLCM(nums, k)); // Output: 4
    }
}
*/
