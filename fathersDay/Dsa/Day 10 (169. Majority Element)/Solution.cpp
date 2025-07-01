#include <vector>

class Solution {
public:
    int majorityElement(std::vector<int>& nums) {
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
};

// Example usage (for testing purposes, not part of the class)
/*
#include <iostream>
int main() {
    Solution sol;
    std::vector<int> nums1 = {3, 2, 3};
    std::cout << "Majority Element: " << sol.majorityElement(nums1) << std::endl; // Output: 3

    std::vector<int> nums2 = {2, 2, 1, 1, 1, 2, 2};
    std::cout << "Majority Element: " << sol.majorityElement(nums2) << std::endl; // Output: 2

    return 0;
}
*/
