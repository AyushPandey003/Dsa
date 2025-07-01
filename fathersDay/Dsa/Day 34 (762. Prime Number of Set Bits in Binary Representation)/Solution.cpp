#include <iostream>
#include <vector>
#include <cmath>

class Solution {
public:
    bool is_prime(int n) {
        if (n < 2) {
            return false;
        }
        for (int i = 2; i <= sqrt(n); ++i) {
            if (n % i == 0) {
                return false;
            }
        }
        return true;
    }

    int countSetBits(int n) {
        int count = 0;
        while (n > 0) {
            n &= (n - 1);
            count++;
        }
        return count;
    }

    int PrimeSetBits(int left, int right) {
        int count = 0;
        for (int num = left; num <= right; ++num) {
            if (is_prime(countSetBits(num))) {
                count++;
            }
        }
        return count;
    }
};

int main() {
    Solution solution;
    int left = 6;
    int right = 10;
    int result = solution.PrimeSetBits(left, right);
    std::cout << result << std::endl; // Output: 4
    return 0;
}
