#include <string>
#include <vector>
#include <algorithm>

class Solution {
public:
    bool checkValidString(std::string s) {
        int leftBalance = 0;
        // First pass: left to right
        // Treat '*' as '(' to maximize open parentheses
        for (char c : s) {
            if (c == '(' || c == '*') {
                leftBalance++;
            } else { // c == ')'
                leftBalance--;
            }
            // If balance drops below zero, it means we have too many ')'
            // that cannot be matched by '(' or '*' (as '(')
            if (leftBalance < 0) {
                return false;
            }
        }

        int rightBalance = 0;
        // Second pass: right to left
        // Treat '*' as ')' to maximize close parentheses
        for (int i = s.length() - 1; i >= 0; --i) {
            char c = s[i];
            if (c == ')' || c == '*') {
                rightBalance++;
            } else { // c == '('
                rightBalance--;
            }
            // If balance drops below zero, it means we have too many '('
            // that cannot be matched by ')' or '*' (as ')')
            if (rightBalance < 0) {
                return false;
            }
        }

        // If both passes complete without balance dropping below zero,
        // it means a valid pairing is possible.
        return true;
    }
};