#include <iostream>
#include <string>
#include <sstream>

class Solution {
public:
    int NumberOfSegments(std::string s) {
        std::stringstream ss(s);
        std::string segment;
        int count = 0;
        while (ss >> segment) {
            count++;
        }
        return count;
    }
};

int main() {
    Solution solution;
    std::string s = "Hello, my name is John";
    int result = solution.NumberOfSegments(s);
    std::cout << result << std::endl; // Output: 5
    return 0;
}
