#include <iostream>
#include <string>
#include <unordered_map>

class Solution {
public:
    int NumberOfSubstrings(std::string s) {
        std::unordered_map<char, int> count;
        int left = 0;
        int result = 0;
        
        for (int right = 0; right < s.length(); ++right) {
            count[s[right]]++;
            
            while (count['a'] > 0 && count['b'] > 0 && count['c'] > 0) {
                result += s.length() - right;
                count[s[left]]--;
                left++;
            }
        }
        
        return result;
    }
};

int main() {
    Solution solution;
    std::string s = "abcabc";
    int result = solution.NumberOfSubstrings(s);
    std::cout << result << std::endl; // Output: 10
    return 0;
}
