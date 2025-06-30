// 3075. Maximize Happiness of Selected Children
// Medium
// Topics
// Companies
// Hint
// You are given an array happiness of length n, and a positive integer k.

// There are n children standing in a queue, where the ith child has happiness value happiness[i]. You want to select k children from these n children in k turns.

// In each turn, when you select a child, the happiness value of all the children that have not been selected till now decreases by 1. Note that the happiness value cannot become negative and gets decremented only if it is positive.

// Return the maximum sum of the happiness values of the selected children you can achieve by selecting k children.

 

// Example 1:

// Input: happiness = [1,2,3], k = 2
// Output: 4
// Explanation: We can pick 2 children in the following way:
// - Pick the child with the happiness value == 3. The happiness value of the remaining children becomes [0,1].
// - Pick the child with the happiness value == 1. The happiness value of the remaining child becomes [0]. Note that the happiness value cannot become less than 0.
// The sum of the happiness values of the selected children is 3 + 1 = 4.
// Example 2:

// Input: happiness = [1,1,1,1], k = 2
// Output: 1
// Explanation: We can pick 2 children in the following way:
// - Pick any child with the happiness value == 1. The happiness value of the remaining children becomes [0,0,0].
// - Pick the child with the happiness value == 0. The happiness value of the remaining child becomes [0,0].
// The sum of the happiness values of the selected children is 1 + 0 = 1.
// Example 3:

// Input: happiness = [2,3,4,5], k = 1
// Output: 5
// Explanation: We can pick 1 child in the following way:
// - Pick the child with the happiness value == 5. The happiness value of the remaining children becomes [1,2,3].
// The sum of the happiness values of the selected children is 5.
#include <vector>
#include <queue>
#include <iostream>
#include <algorithm>

using namespace std;

long long maxHappiness(vector<int>& arr, int k) {
  sort(arr.begin(),arr.end(),greater<int>());
        long long int ans=0;
        for(int i=0;i<k;i++){
            if((arr[i]-i)>=0)ans+=(arr[i]-i);
        }
        return ans;
}

int main() {
    vector<int> happiness = {1, 2, 3};
    int k = 2;
    cout << "Maximum sum of happiness: " << maxHappiness(happiness, k) << endl;
    return 0;
}

// Function Definition: The function maxHappiness is defined which takes a vector of integers arr and an integer k as input. The vector arr represents the happiness values and k is the number of elements to be selected from arr.
// Sorting: The vector arr is sorted in descending order using the sort function from the <algorithm> library. This is done so that the highest values are at the beginning of the vector.
// Initialization: A variable ans of type long long int is initialized to 0. This variable is used to store the sum of the maximum k elements in arr.
// Loop: A for loop is run from i = 0 to i = k-1. In each iteration, it checks if the value of the ith element in arr minus i is greater than or equal to 0. If it is, it adds the value of arr[i] - i to ans.
// Return: The function returns the value of ans, which is the maximum sum of happiness that can be obtained by selecting k elements from arr.
// Main Function: In the main function, a vector happiness is defined with values {1, 2, 3} and k is set to 2. The maxHappiness function is then called with happiness and k as arguments, and its return value is printed to the console.


// class Solution {
// public:
//     long long maximumHappinessSum(vector<int>& arr, int k) {
//         sort(arr.begin(),arr.end(),greater<int>());
//         long long int ans=0;
//         for(int i=0;i<k;i++){
//             if((arr[i]-i)>=0)ans+=(arr[i]-i);
//         }
//         return ans;
//     }
// };
// 1. **Initialize a max heap**: This will be used to store the happiness values of the children. The max heap is chosen because it allows us to efficiently select the child with the highest happiness in each turn.

// 2. **Populate the heap**: Iterate over the happiness array and push each happiness value into the max heap.

// 3. **Initialize total happiness**: This variable will keep track of the total happiness of the selected children.

// 4. **Selection of children**: Repeat the following steps until `k` children have been selected or the heap is empty:
//     - **Select the happiest child**: Extract the maximum value from the heap (which represents the happiness of the happiest child) and add it to the total happiness.
//     - **Decrease happiness**: Create a temporary array and populate it with the happiness values of the remaining children, each decreased by 1. Note that the happiness value cannot become less than 0.
//     - **Update the heap**: Clear the heap and repopulate it with the updated happiness values from the temporary array.

// 5. **Return the total happiness**: After `k` children have been selected, the total happiness variable holds the maximum sum of happiness that can be achieved.
 
// This algorithm ensures that in each turn, the child with the highest happiness is always selected, and the happiness of the remaining children is correctly decreased. It has a time complexity of O(n log n) due to the use of a heap, where n is the number of children. The space complexity is also O(n) for storing the happiness values in the heap. 