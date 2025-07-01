#include <iostream>

class Solution {
public:
    int NumberOfoneBits(int n) {
        int count = 0;
        while (n) {
            count += n & 1;
            n >>= 1;
        }
        return count;
    }
};

int main() {
    Solution solution;
    int n = 11; // Binary representation: 1011
    int result = solution.NumberOfoneBits(n);
    std::cout << result << std::endl; // Output: 3
    return 0;
}
