// You are given an m x n binary matrix grid.

// A move consists of choosing any row or column and toggling each value in that row or column (i.e., changing all 0's to 1's, and all 1's to 0's).

// Every row of the matrix is interpreted as a binary number, and the score of the matrix is the sum of these numbers.

// Return the highest possible score after making any number of moves (including zero moves).

 

// Example 1:


// Input: grid = [[0,0,1,1],[1,0,1,0],[1,1,0,0]]
// Output: 39
// Explanation: 0b1111 + 0b1001 + 0b1111 = 15 + 9 + 15 = 39
// Example 2:

// Input: grid = [[0]]
// Output: 1


// Input: grid = [[0]]
// Output: 1 give solution in cpp
// ChatGPT
// To solve the problem of finding the highest possible score for a binary matrix after performing any number of row and column toggles, you should focus on maximizing each binary number represented by each row of the matrix.

// Key Insight:
// For any column in the matrix, if toggling that column results in more 1s than 0s in that column, you should perform the toggle. Similarly, each row should be maximized to its potential binary value by ensuring the most significant bit (MSB) is 1, as the MSB contributes the most to the binary number's value. You do not need to toggle the whole matrix for optimal scoring; instead, you toggle specific rows and columns strategically.

// The logic to maximize the score:

// Ensure each row starts with a 1 by toggling rows that have a 0 in the leftmost (most significant) column.
// After ensuring the leftmost column is set to 1s, focus on subsequent columns. For each column, if the number of 0s exceeds the number of 1s, toggle that column to maximize 1s.
// Step-by-step Approach:

// Start by checking and toggling rows if the most significant bit (leftmost column in each row) is 0.
// For each column, calculate the number of 1s after ensuring the MSB of each row is 1. If the number of 0s is greater, toggle the column.


#include <vector>
#include <iostream>
#include <cmath> // for pow function

using namespace std;

class Solution {
public:
    int matrixScore(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int total_score = 0;
        for (int i = 0; i < m; ++i) {
            if (grid[i][0] == 0) {
                for (int j = 0; j < n; ++j) {
                    grid[i][j] = 1 - grid[i][j]; // toggle operation
                }
            }
        }
        for (int j = 0; j < n; ++j) {
            int count_ones = 0;
            for (int i = 0; i < m; ++i) {
                count_ones += grid[i][j]; 
            }
            int max_ones = max(count_ones, m - count_ones); 
            total_score += max_ones * (1 << (n - j - 1)); 
        }
        return total_score;
    }
};
int main() {
    Solution sol;
    vector<vector<int>> grid1 = {{0,0,1,1},{1,0,1,0},{1,1,0,0}};
    cout << "Output: " << sol.matrixScore(grid1) << endl; // Expected: 39

    vector<vector<int>> grid2 = {{0}};
    cout << "Output: " << sol.matrixScore(grid2) << endl; // Expected: 1
    return 0;
}
