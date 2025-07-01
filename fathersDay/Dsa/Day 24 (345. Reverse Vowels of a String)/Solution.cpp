#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>

class Solution {
public:
    std::string ReverseVowels(std::string s) {
        std::unordered_set<char> vowels = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
        int left = 0, right = s.length() - 1;
        while (left < right) {
            while (left < right && vowels.find(s[left]) == vowels.end()) {
                left++;
            }
            while (left < right && vowels.find(s[right]) == vowels.end()) {
                right--;
            }
            if (left < right) {
                std::swap(s[left++], s[right--]);
            }
        }
        return s;
    }
};

int main() {
    Solution solution;
    std::string s = "hello";
    std::string result = solution.ReverseVowels(s);
    std::cout << '"' << result << '"' << std::endl; // Output: "holle"
    return 0;
}
