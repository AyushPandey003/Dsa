#include <iostream>
#include <string>

class Solution {
public:
    bool RotateString(std::string s, std::string goal) {
        if (s.length() != goal.length()) {
            return false;
        }
        std::string doubled_s = s + s;
        return doubled_s.find(goal) != std::string::npos;
    }
};

int main() {
    Solution solution;
    std::string s = "abcde";
    std::string goal = "cdeab";
    bool result = solution.RotateString(s, goal);
    std::cout << (result ? "True" : "False") << std::endl; // Output: True
    return 0;
}
