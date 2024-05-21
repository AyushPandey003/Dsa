#include <iostream>
#include <vector>

// Define the Solution class with the subsets method
class Solution {
public:
    std::vector<std::vector<int>> subsets(std::vector<int>& nums) {
        std::vector<std::vector<int>> result = {{}};
        
        for (int num : nums) {
            int n = result.size();
            for (int i = 0; i < n; ++i) {
                std::vector<int> subset = result[i];
                subset.push_back(num);
                result.push_back(subset);
            }
        }
        
        return result;
    }
};

// Function to print the subsets
void printSubsets(const std::vector<std::vector<int>>& subsets) {
    std::cout << "[";
    for (size_t i = 0; i < subsets.size(); ++i) {
        std::cout << "[";
        for (size_t j = 0; j < subsets[i].size(); ++j) {
            std::cout << subsets[i][j];
            if (j < subsets[i].size() - 1) {
                std::cout << ",";
            }
        }
        std::cout << "]";
        if (i < subsets.size() - 1) {
            std::cout << ",";
        }
    }
    std::cout << "]" << std::endl;
}

int main() {
    Solution solution;

    // Test case 1
    std::vector<int> nums1 = {1, 2, 3};
    std::vector<std::vector<int>> result1 = solution.subsets(nums1);
    std::cout << "Subsets of [1, 2, 3]:" << std::endl;
    printSubsets(result1);

    // Test case 2
    std::vector<int> nums2 = {0};
    std::vector<std::vector<int>> result2 = solution.subsets(nums2);
    std::cout << "Subsets of [0]:" << std::endl;
    printSubsets(result2);

    return 0;
}
