#include <vector>
#include <algorithm>

class Solution {
public:
    void moveZeroes(std::vector<int>& nums) {
        int lastNonZeroFoundAt = 0;
        // Iterate through the array. If a non-zero element is found,
        // it is copied to the position indicated by lastNonZeroFoundAt
        // and lastNonZeroFoundAt is incremented.
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] != 0) {
                nums[lastNonZeroFoundAt++] = nums[i];
            }
        }
        
        // After moving all non-zero elements to the beginning,
        // fill the rest of the array with zeros.
        for (int i = lastNonZeroFoundAt; i < nums.size(); ++i) {
            nums[i] = 0;
        }
    }
};