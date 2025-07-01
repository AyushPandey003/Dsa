#include <iostream>
#include <string>
#include <algorithm>

class Solution {
public:
    std::string makeSmallestPalindrome(std::string s) {
        int left = 0;
        int right = s.length() - 1;
        while (left < right) {
            if (s[left] != s[right]) {
                if (s[left] < s[right]) {
                    s[right] = s[left];
                } else {
                    s[left] = s[right];
                }
            }
            left++;
            right--;
        }
        return s;
    }
};

int main() {
    Solution solution;
    std::string s = "egcfe";
    std::cout << solution.makeSmallestPalindrome(s) << std::endl; // Output: "efcfe"
    return 0;
}
