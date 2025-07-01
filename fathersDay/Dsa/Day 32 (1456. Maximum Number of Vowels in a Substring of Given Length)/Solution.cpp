#include <iostream>
#include <string>
#include <unordered_set>
#include <algorithm>

class Solution {
public:
    int MaximumVowels(std::string s, int k) {
        std::unordered_set<char> vowels = {'a', 'e', 'i', 'o', 'u'};
        int max_vowels = 0;
        int current_vowels = 0;

        for (int i = 0; i < s.length(); ++i) {
            if (i >= k) {
                if (vowels.count(s[i - k])) {
                    current_vowels--;
                }
            }
            if (vowels.count(s[i])) {
                current_vowels++;
            }
            if (i >= k - 1) {
                max_vowels = std::max(max_vowels, current_vowels);
            }
        }
        return max_vowels;
    }
};

int main() {
    Solution solution;
    std::string s = "abciiidef";
    int k = 3;
    int result = solution.MaximumVowels(s, k);
    std::cout << result << std::endl; // Output: 3
    return 0;
}
