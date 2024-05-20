// Implement pow(x, n) % M.
// In other words, for a given value of x, n, and M, find  (xn) % M.
#include <iostream>
using namespace std;

long long modPow(long long x, long long n, long long M) {
    long long result = 1;
    x = x % M; // Update x if it is more than or equal to M

    if (x == 0) return 0; // In case x is divisible by M

    while (n > 0) {
        // If n is odd, multiply x with the result
        if (n % 2 == 1)
            result = (result * x) % M;

        // n must be even now
        n = n >> 1; // n = n / 2
        x = (x * x) % M; // Change x to x^2
    }
    return result;
}

int main() {
    long long x = 2;
    long long n = 10;
    long long M = 1000;
    cout << "Result of (2^10) % 1000: " << modPow(x, n, M) << endl;

    x = 3;
    n = 13;
    M = 50;
    cout << "Result of (3^13) % 50: " << modPow(x, n, M) << endl;

    return 0;
}
