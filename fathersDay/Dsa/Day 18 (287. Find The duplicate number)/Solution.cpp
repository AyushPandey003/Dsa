#include <vector>
#include <iostream>

class Solution {
public:
    int findDuplicate(std::vector<int>& nums) {
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
};

/*
// Example usage:
int main() {
    Solution sol;
    std::vector<int> nums = {3, 1, 3, 4, 2};
    std::cout << "The duplicate number is: " << sol.findDuplicate(nums) << std::endl; // Expected: 3
    return 0;
}
*/