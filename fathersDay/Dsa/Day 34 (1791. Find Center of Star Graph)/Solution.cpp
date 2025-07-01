#include <iostream>
#include <vector>
#include <unordered_map>

class Solution {
public:
    int CenterOfStarGraph(std::vector<std::vector<int>>& edges) {
        std::unordered_map<int, int> degree;
        for (const auto& edge : edges) {
            degree[edge[0]]++;
            degree[edge[1]]++;
        }
        int n = edges.size() + 1;
        for (const auto& pair : degree) {
            if (pair.second == n - 1) {
                return pair.first;
            }
        }
        return -1;
    }
};

int main() {
    Solution solution;
    std::vector<std::vector<int>> edges = {{1, 2}, {2, 3}, {4, 2}};
    int result = solution.CenterOfStarGraph(edges);
    std::cout << result << std::endl; // Output: 2
    return 0;
}
