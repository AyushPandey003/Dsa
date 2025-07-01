#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

class Solution {
public:
    bool isPalindrome(const std::string& s) {
        std::string reversed_s = s;
        std::reverse(reversed_s.begin(), reversed_s.end());
        return s == reversed_s;
    }

    std::string FindFirstPalindromic(std::vector<std::string>& words) {
        for (const std::string& word : words) {
            if (isPalindrome(word)) {
                return word;
            }
        }
        return "";
    }
};

int main() {
    Solution solution;
    std::vector<std::string> words = {"abc", "car", "ada", "racecar", "cool"};
    std::string result = solution.FindFirstPalindromic(words);
    std::cout << '"' << result << '"' << std::endl; // Output: "ada"
    return 0;
}
