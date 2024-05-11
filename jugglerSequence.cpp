#include <iostream>
#include <vector>
#include <cmath>  // For pow() and floor()

class Solution {
public:
    std::vector<long long> jugglerSequence(long long n) {
        std::vector<long long> sequence;
        sequence.push_back(n); // Add the initial number to the sequence

        while (n != 1) {
            long long next;
            if (n % 2 == 0) {
                // Next term if n is even
                next = (long long)std::floor(std::pow(n, 0.5));
            } else {
                // Next term if n is odd
                next = (long long)std::floor(std::pow(n, 1.5));
            }
            sequence.push_back(next);
            n = next; // Update n to the next term
        }

        return sequence;
    }
};

int main() {
    Solution solution;
    long long n = 9;
    std::vector<long long> result = solution.jugglerSequence(n);

    // Output the sequence
    for (long long num : result) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}
// Juggler Sequence is a series of integers in which the first term starts with a positive integer number a and the remaining terms are generated from the immediate previous term using the below recurrence relation:

// Juggler Formula

// Given a number n, find the Juggler Sequence for this number as the first term of the sequence until it becomes 1.


// Example 1:

// Input: n = 9
// Output: 9 27 140 11 36 6 2 1
// Explaination: We start with 9 and use 
// above formula to get next terms.