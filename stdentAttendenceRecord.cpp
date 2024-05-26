// An attendance record for a student can be represented as a string where each character signifies whether the student was absent, late, or present on that day. The record only contains the following three characters:

// 'A': Absent.
// 'L': Late.
// 'P': Present.
// Any student is eligible for an attendance award if they meet both of the following criteria:

// The student was absent ('A') for strictly fewer than 2 days total.
// The student was never late ('L') for 3 or more consecutive days.
// Given an integer n, return the number of possible attendance records of length n that make a student eligible for an attendance award. The answer may be very large, so return it modulo 109 + 7.

 

// Example 1:

// Input: n = 2
// Output: 8
// Explanation: There are 8 records with length 2 that are eligible for an award:
// "PP", "AP", "PA", "LP", "PL", "AL", "LA", "LL"
// Only "AA" is not eligible because there are 2 absences (there need to be fewer than 2).
// Example 2:

// Input: n = 1
// Output: 3
// Example 3:

// Input: n = 10101
// Output: 183236316
 

// Constraints:

// 1 <= n <= 105
#include <iostream>
#include <vector>

using namespace std;

const int MOD = 1000000007;

int checkRecord(int n) {
    // dp[i][j][k] - number of valid records of length i with j 'A's and k consecutive 'L's at the end
    vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(2, vector<int>(3, 0)));
    
    // Initialization for length 0
    dp[0][0][0] = 1;
    
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < 2; ++j) {  // number of A's
            for (int k = 0; k < 3; ++k) {  // number of consecutive L's
                if (dp[i][j][k] == 0) continue;
                
                // Add 'P'
                dp[i + 1][j][0] = (dp[i + 1][j][0] + dp[i][j][k]) % MOD;
                
                // Add 'A' if there are currently fewer than 1 'A'
                if (j < 1) {
                    dp[i + 1][j + 1][0] = (dp[i + 1][j + 1][0] + dp[i][j][k]) % MOD;
                }
                
                // Add 'L' if there are currently fewer than 2 consecutive 'L's
                if (k < 2) {
                    dp[i + 1][j][k + 1] = (dp[i + 1][j][k + 1] + dp[i][j][k]) % MOD;
                }
            }
        }
    }
    
    // Sum up all valid states of length n
    int result = 0;
    for (int j = 0; j < 2; ++j) {
        for (int k = 0; k < 3; ++k) {
            result = (result + dp[n][j][k]) % MOD;
        }
    }
    
    return result;
}

int main() {
    int n;
    cin >> n;
    cout << checkRecord(n) << endl;
    return 0;
}
