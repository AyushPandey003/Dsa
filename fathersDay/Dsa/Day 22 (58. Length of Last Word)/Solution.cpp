#include <iostream>
#include <string>
#include <algorithm>

class Solution {
public:
    int LengthOfLastWord(std::string s) {
        // Trim trailing spaces
        int end = s.length() - 1;
        while (end >= 0 && s[end] == ' ') {
            end--;
        }
        if (end < 0) {
            return 0;
        }
        // Find the start of the last word
        int start = end;
        while (start >= 0 && s[start] != ' ') {
            start--;
        }
        return end - start;
    }
};

int main() {
    Solution solution;
    std::string s = "Hello World";
    std::cout << solution.LengthOfLastWord(s) << std::endl; // Output: 5
    return 0;
}
