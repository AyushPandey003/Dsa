#include <vector>

class Solution {
public:
    std::vector<int> getRow(int rowIndex) {
        if (rowIndex < 0) {
            return {}; // Return an empty vector for negative rowIndex
        }
        
        // Initialize a 2D vector to store the triangle up to rowIndex
        // Each row i will have i+1 elements
        std::vector<std::vector<int>> triangle(rowIndex + 1);
        
        for (int i = 0; i <= rowIndex; ++i) {
            triangle[i].resize(i + 1, 1); // Initialize with 1s
        }
        
        // Fill in the values based on Pascal's rule
        for (int i = 2; i <= rowIndex; ++i) {
            for (int j = 1; j < i; ++j) {
                triangle[i][j] = triangle[i - 1][j - 1] + triangle[i - 1][j];
            }
        }
        
        return triangle[rowIndex];
    }
};