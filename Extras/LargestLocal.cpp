// you are given an n x n integer matrix grid.

// Generate an integer matrix maxLocal of size (n - 2) x (n - 2) such that:

// maxLocal[i][j] is equal to the largest value of the 3 x 3 matrix in grid centered around row i + 1 and column j + 1.
// In other words, we want to find the largest value in every contiguous 3 x 3 matrix in grid.

// Return the generated matrix. Input: grid = [[9,9,8,1],[5,6,2,6],[8,2,6,4],[6,2,2,2]]
// Output: [[9,9],[8,6]]
// Explanation: The diagram above shows the original matrix and the generated matrix.
// Notice that each value in the generated matrix corresponds to the largest value of a contiguous 3 x 3 matrix in grid. 

#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

vector<vector<int>> largestLocal(vector<vector<int>>& grid) {
    int n = grid.size();
    vector<vector<int>> maxLocal(n - 2, vector<int>(n - 2));

    for (int i = 0; i < n - 2; ++i) {
        for (int j = 0; j < n - 2; ++j) {
            int maxVal = grid[i][j]; 
            for (int x = 0; x < 3; ++x) {
                for (int y = 0; y < 3; ++y) {
                    maxVal = max(maxVal, grid[i + x][j + y]);
                }
            }
            maxLocal[i][j] = maxVal;
        }
    }

    return maxLocal;
}

int main() {
    vector<vector<int>> grid = {
        {9, 9, 8, 1},
        {5, 6, 2, 6},
        {8, 2, 6, 4},
        {6, 2, 2, 2}
    };

    vector<vector<int>> result = largestLocal(grid);
    for (const auto& row : result) {
        for (int val : row) {
            cout << val << " ";
        }
        cout << "\n";
    }

    return 0;
}
