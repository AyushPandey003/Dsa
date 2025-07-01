#include <vector>
#include <numeric> // For std::gcd in C++17

// Helper function for GCD
long long calculateGcd(long long a, long long b) {
    return std::gcd(a, b);
}

// Helper function for LCM, handling potential overflow
long long calculateLcm(long long a, long long b) {
    if (a == 0 || b == 0) return 0;
    // To prevent overflow: lcm(a, b) = (a / gcd(a, b)) * b
    // Or, if a * b is guaranteed not to overflow, (a * b) / gcd(a, b)
    // Given constraints, a * b might overflow int, so use long long.
    // The problem states k <= 1000, so intermediate LCMs can exceed int max.
    return (a / calculateGcd(a, b)) * b;
}

class Solution {
public:
    int subarrayLCM(std::vector<int>& nums, int k) {
        int n = nums.size();
        int count = 0;

        if (k == 0) {
            return 0;
        }

        for (int i = 0; i < n; ++i) {
            long long current_lcm = nums[i]; // Use long long to prevent overflow

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
};

// Example usage (for testing purposes, not part of the class)
/*
#include <iostream>
int main() {
    Solution sol;
    std::vector<int> nums = {3, 6, 2, 7, 1};
    int k = 6;
    std::cout << "Number of subarrays with LCM equal to k: " << sol.subarrayLCM(nums, k) << std::endl; // Output: 4
    return 0;
}
*/
