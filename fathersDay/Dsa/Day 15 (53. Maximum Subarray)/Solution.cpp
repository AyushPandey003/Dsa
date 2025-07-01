#include <vector>
#include <algorithm> // For std::max

class Solution {
public:
    int maxSubArray(std::vector<int>& nums) {
        if (nums.empty()) {
            // According to problem constraints, nums contains at least one number.
            // However, for robustness, handle empty case.
            return 0; 
        }
        
        int maxSum = nums[0];
        int currentSum = nums[0];
        
        for (size_t i = 1; i < nums.size(); ++i) {
            // currentSum = max(current_element, current_element + current_sum_so_far)
            currentSum = std::max(nums[i], currentSum + nums[i]);
            
            // maxSum = max(overall_max_sum, current_sum)
            maxSum = std::max(maxSum, currentSum);
        }
        
        return maxSum;
    }
};