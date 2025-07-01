#include <iostream>
#include <vector>

class Solution {
public:
    int FindJudge(int n, std::vector<std::vector<int>>& trust) {
        if (n == 1 && trust.empty()) {
            return 1;
        }
        
        std::vector<int> trust_count(n + 1, 0);
        std::vector<int> trusted_by(n + 1, 0);
        
        for (const auto& pair : trust) {
            trust_count[pair[0]]++;
            trusted_by[pair[1]]++;
        }
        
        for (int i = 1; i <= n; ++i) {
            if (trust_count[i] == 0 && trusted_by[i] == n - 1) {
                return i;
            }
        }
        
        return -1;
    }
};

int main() {
    Solution solution;
    int n = 3;
    std::vector<std::vector<int>> trust = {{1, 2}, {2, 3}};
    int result = solution.FindJudge(n, trust);
    std::cout << result << std::endl; // Output: -1
    return 0;
}
