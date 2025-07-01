#include <iostream>
#include <string>
#include <numeric>

class Solution {
public:
    std::string GreatestCommonDivisor(std::string str1, std::string str2) {
        if (str1 + str2 != str2 + str1) {
            return "";
        }
        return str1.substr(0, std::gcd(str1.length(), str2.length()));
    }
};

int main() {
    Solution solution;
    std::string str1 = "ABCABC";
    std::string str2 = "ABC";
    std::string result = solution.GreatestCommonDivisor(str1, str2);
    std::cout << result << std::endl; // Output: "ABC"
    return 0;
}
