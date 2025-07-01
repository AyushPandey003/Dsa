#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

class Solution {
public:
    std::string LongestCommonPrefix(std::vector<std::string>& strs) {
        if (strs.empty()) {
            return "";
        }
        std::string prefix = strs[0];
        for (size_t i = 1; i < strs.size(); ++i) {
            while (strs[i].find(prefix) != 0) {
                prefix = prefix.substr(0, prefix.length() - 1);
                if (prefix.empty()) {
                    return "";
                }
            }
        }
        return prefix;
    }
};

int main() {
    Solution solution;
    std::vector<std::string> strs = {"flower", "flow", "flight"};
    std::string result = solution.LongestCommonPrefix(strs);
    std::cout << '"' << result << '"' << std::endl; // Output: "fl"
    return 0;
}
