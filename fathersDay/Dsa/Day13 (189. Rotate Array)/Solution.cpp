#include <vector>
#include <algorithm>

class Solution {
public:
    void rotate(std::vector<int>& nums, int k) {
        int n = nums.size();
        k %= n; // Handle cases where k is greater than n

        if (k == 0) {
            return;
        }

        // Reverse the entire array
        std::reverse(nums.begin(), nums.end());
        
        // Reverse the first k elements
        std::reverse(nums.begin(), nums.begin() + k);
        
        // Reverse the remaining n-k elements
        std::reverse(nums.begin() + k, nums.end());
    }
};