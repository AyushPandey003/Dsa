class Solution {
    public int maxSubArray(int[] nums) {
        if (nums == null || nums.length == 0) {
            // According to problem constraints, nums contains at least one number.
            // However, for robustness, handle empty case.
            return 0;
        }
        
        int maxSum = nums[0];
        int currentSum = nums[0];
        
        for (int i = 1; i < nums.length; i++) {
            // currentSum = Math.max(current_element, current_element + current_sum_so_far)
            currentSum = Math.max(nums[i], currentSum + nums[i]);
            
            // maxSum = Math.max(overall_max_sum, current_sum)
            maxSum = Math.max(maxSum, currentSum);
        }
        
        return maxSum;
    }
}