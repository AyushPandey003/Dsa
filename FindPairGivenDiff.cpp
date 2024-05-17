// Given an array arr[] of size n and an integer x, return 1 if there exists a pair of elements in the array whose absolute difference is x, otherwise, return -1.

// Example 1:

// Input:
// n = 6
// x = 78
// arr[] = {5, 20, 3, 2, 5, 80}
// Output:
// 1
// Explanation:
// Pair (2, 80) have absolute difference of 78.
// Example 2:

// Input:
// n = 5
// x = 45
// arr[] = {90, 70, 20, 80, 50}
// Output:
// -1
// Explanation:
// There is no pair with absolute difference of 45.
// Your Task:
// You need not take input or print anything. Your task is to complete the function findPair() which takes integers n, x, and an array arr[] as input parameters and returns 1 if the required pair exists, return -1 otherwise.

// Expected Time Complexity: O(n* Log(n)).
// Expected Auxiliary Space: O(1).

// Constraints:
// 1<=n<=106 
// 1<=arr[i]<=106 
// 0<=x<=105

#include <iostream>
#include <unordered_set>
using namespace std;

class Solution {
public:
    int findPair(int arr[], int n, int x) {
        unordered_set<int> elements;
        
        for (int i = 0; i < n; ++i) {
            // Check if there exists an element with difference x
            if (elements.find(arr[i] - x) != elements.end() ||
                elements.find(arr[i] + x) != elements.end()) {
                return 1;
            }
            // Insert the current element into the set
            elements.insert(arr[i]);
        }
        
        return -1;
    }
};

int main() {
    Solution solution;
    
    int arr1[] = {5, 20, 3, 2, 5, 80};
    int n1 = 6;
    int x1 = 78;
    cout << solution.findPair(arr1, n1, x1) << endl; // Output: 1

    int arr2[] = {90, 70, 20, 80, 50};
    int n2 = 5;
    int x2 = 45;
    cout << solution.findPair(arr2, n2, x2) << endl; // Output: -1
    
    return 0;
}
