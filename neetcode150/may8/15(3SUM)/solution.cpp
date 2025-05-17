#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath> // For abs function
using namespace std;


vector<vector<int>> threeSumExactTriplets(vector<int>& nums, int target) {
    int n = nums.size();
    sort(nums.begin(), nums.end());
    vector<vector<int>> triplets;

    for (int i = 0; i < n - 2; i++) {
        if (i > 0 && nums[i] == nums[i-1]) continue;
        int left = i + 1, right = n - 1;
        while (left < right) {
            int sum = nums[i] + nums[left] + nums[right];
            if (sum == target) {
                triplets.push_back({nums[i], nums[left], nums[right]});
                // Skip duplicates
                while (left < right && nums[left] == nums[left+1]) left++;
                while (left < right && nums[right] == nums[right-1]) right--;
                left++;
                right--;
            } else if (sum < target) {
                left++;
            } else {
                right--;
            }
        }
    }
    return triplets;
}
int main() {
    vector<int> nums = {-1, 0, 1, 2, -1, -4};
    int target = 0;
    vector<vector<int>> result = threeSumExactTriplets(nums, target);
    
    cout << "Triplets: " << endl;
    for (const auto& triplet : result) {
        cout << "[" << triplet[0] << ", " << triplet[1] << ", " << triplet[2] << "]" << endl;
    }
    
    return 0;
}
