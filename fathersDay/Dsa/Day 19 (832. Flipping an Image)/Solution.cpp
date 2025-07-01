#include <iostream>
#include <vector>
#include <algorithm>

class Solution {
public:
    std::vector<std::vector<int>> flipAndInvertImage(std::vector<std::vector<int>>& image) {
        for (auto& row : image) {
            std::reverse(row.begin(), row.end());
            for (int& pixel : row) {
                pixel = 1 - pixel;
            }
        }
        return image;
    }
};

int main() {
    Solution solution;
    std::vector<std::vector<int>> image = {{1, 1, 0}, {1, 0, 1}, {0, 0, 0}};
    std::vector<std::vector<int>> result = solution.flipAndInvertImage(image);
    for (const auto& row : result) {
        for (int pixel : row) {
            std::cout << pixel << " ";
        }
        std::cout << std::endl;
    }
    // Expected Output:
    // 1 0 0 
    // 0 1 0 
    // 1 1 1 
    return 0;
}
