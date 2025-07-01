class Solution {
    // Function to calculate GCD using Euclidean algorithm
    private int calculateGCD(int a, int b) {
        while (b != 0) {
            int temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }

    public int findGCD(int[] nums) {
        // Find the minimum and maximum elements in the array
        int minVal = nums[0];
        int maxVal = nums[0];

        for (int num : nums) {
            if (num < minVal) {
                minVal = num;
            }
            if (num > maxVal) {
                maxVal = num;
            }
        }
        
        // Return the GCD of the minimum and maximum elements
        return calculateGCD(minVal, maxVal);
    }
}