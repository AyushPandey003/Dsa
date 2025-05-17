#include <iostream>
using namespace std;
#include <unordered_map>
#include <vector>

vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int, int> num_map; 
    vector<int> result;

    for (int i = 0; i < nums.size(); i++) {
        int complement = target - nums[i]; 
        if (num_map.find(complement) != num_map.end()) { 
            result.push_back(num_map[complement]); 
            result.push_back(i);
            return result;
        }
        num_map[nums[i]] = i; 
    }
    return result; 
}

int main(){
    vector<int> nums = {2, 7, 11, 15};
    int target = 9;
    vector<int> result = twoSum(nums, target);
    cout << "Indices: " << result[0] << ", " << result[1] << endl;
    return 0;
}