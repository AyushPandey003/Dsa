
// 8. String to Integer (atoi)
// Solved
// Medium
// Topics
// Companies
// Implement the myAtoi(string s) function, which converts a string to a 32-bit signed integer.

// The algorithm for myAtoi(string s) is as follows:

// Whitespace: Ignore any leading whitespace (" ").
// Signedness: Determine the sign by checking if the next character is '-' or '+', assuming positivity is neither present.
// Conversion: Read the integer by skipping leading zeros until a non-digit character is encountered or the end of the string is reached. If no digits were read, then the result is 0.
// Rounding: If the integer is out of the 32-bit signed integer range [-231, 231 - 1], then round the integer to remain in the range. Specifically, integers less than -231 should be rounded to -231, and integers greater than 231 - 1 should be rounded to 231 - 1.
// Return the integer as the final result.

 

// Example 1:

// Input: s = "42"

// Output: 42

// Explanation:

// The underlined characters are what is read in and the caret is the current reader position.
// Step 1: "42" (no characters read because there is no leading whitespace)
//          ^
// Step 2: "42" (no characters read because there is neither a '-' nor '+')
//          ^
// Step 3: "42" ("42" is read in)
//            ^


// class Solution {
// public:
//     int myAtoi(string s) {
        
//          int i = 0, sign = 1;
//     long result = 0;

//     // Skip whitespaces
//     while (i < s.size() && isspace(s[i])) ++i;

//     // Check for sign
//     if (i < s.size() && (s[i] == '-' || s[i] == '+')) {
//         sign = (s[i++] == '-') ? -1 : 1;
//     }

//     // Convert number
//     while (i < s.size() && isdigit(s[i])) {
//         if (result > INT_MAX / 10 || (result == INT_MAX / 10 && s[i] - '0' > INT_MAX % 10)) {
//             return sign == 1 ? INT_MAX : INT_MIN;
//         }
//         result = result * 10 + (s[i++] - '0');
//     }

//     return sign * result;
// }
        
// };
#include <vector>
#include <queue>
#include <iostream>
#include <algorithm>
#include <cctype>
#include <climits>

using namespace std;

int myAtoi(string s) {
    int i = 0, sign = 1;
    long result = 0;
    while (i < s.size() && isspace(s[i])) ++i;
    if (i < s.size() && (s[i] == '-' || s[i] == '+')) {
        sign = (s[i++] == '-') ? -1 : 1;
    }
    while (i < s.size() && isdigit(s[i])) {
        if (result > INT_MAX / 10 || (result == INT_MAX / 10 && s[i] - '0' > INT_MAX % 10)) {
            return sign == 1 ? INT_MAX : INT_MIN;
        }
        result = result * 10 + (s[i++] - '0');
    }

    return sign * result;
}


int main() {
    string s = "-42";
    int result = myAtoi(s);
    cout << "The converted integer is: " << result << endl;
    return 0;
}

