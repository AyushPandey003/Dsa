#include <iostream>
#include <string>
#include <stack>
#include <algorithm>

class Solution {
public:
    std::string RemoveDuplicates(std::string s) {
        std::string result = "";
        for (char c : s) {
            if (!result.empty() && result.back() == c) {
                result.pop_back();
            } else {
                result.push_back(c);
            }
        }
        return result;
    }
};

int main() {
    Solution solution;
    std::string s = "abbaca";
    std::string result = solution.RemoveDuplicates(s);
    std::cout << '"' << result << '"' << std::endl; // Output: "ca"
    return 0;
}
