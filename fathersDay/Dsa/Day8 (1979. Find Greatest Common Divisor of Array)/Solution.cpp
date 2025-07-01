#include <vector>
#include <algorithm> // For std::min_element, std::max_element
#include <numeric>   // For std::gcd (C++17)

class Solution {
public:
    // Function to calculate GCD using Euclidean algorithm
    int calculateGCD(int a, int b) {
        while (b != 0) {
            int temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }

    int findGCD(std::vector<int>& nums) {
        // Find the minimum and maximum elements in the array
        int min_val = nums[0];
        int max_val = nums[0];

        for (int num : nums) {
            if (num < min_val) {
                min_val = num;
            }
            if (num > max_val) {
                max_val = num;
            }
        }
        
        // Alternatively, using standard library functions (C++11 for min/max_element)
        // int min_val = *std::min_element(nums.begin(), nums.end());
        // int max_val = *std::max_element(nums.begin(), nums.end());

        // Return the GCD of the minimum and maximum elements
        // Using std::gcd (C++17) or custom calculateGCD function
        return calculateGCD(min_val, max_val);
        // return std::gcd(min_val, max_val); // For C++17 and above
    }
};