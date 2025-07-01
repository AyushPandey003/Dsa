#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>

class Solution {
public:
    std::string ReverseWords(std::string s) {
        std::stringstream ss(s);
        std::string word;
        std::vector<std::string> words;
        while (ss >> word) {
            words.push_back(word);
        }
        std::reverse(words.begin(), words.end());
        std::string result;
        for (size_t i = 0; i < words.size(); ++i) {
            result += words[i];
            if (i < words.size() - 1) {
                result += " ";
            }
        }
        return result;
    }
};

int main() {
    Solution solution;
    std::string words = "the sky is blue";
    std::string result = solution.ReverseWords(words);
    std::cout << '"' << result << '"' << std::endl; // Output: "blue is sky the"
    return 0;
}
