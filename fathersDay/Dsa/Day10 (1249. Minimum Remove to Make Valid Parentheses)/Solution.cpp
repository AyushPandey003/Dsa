#include <string>
#include <stack>
#include <algorithm>

class Solution {
public:
    std::string minRemoveToMakeValid(std::string s) {
        std::string result = "";
        int balance = 0;

        // First pass: remove invalid ')'
        for (char c : s) {
            if (c == '(') {
                balance++;
                result += c;
            } else if (c == ')') {
                if (balance > 0) {
                    balance--;
                    result += c;
                }
            } else {
                result += c;
            }
        }

        std::string finalResult = "";
        balance = 0;

        // Second pass: remove invalid '(' from the reversed string
        for (int i = result.length() - 1; i >= 0; --i) {
            char c = result[i];
            if (c == ')') {
                balance++;
                finalResult += c;
            } else if (c == '(') {
                if (balance > 0) {
                    balance--;
                    finalResult += c;
                }
            } else {
                finalResult += c;
            }
        }
        std::reverse(finalResult.begin(), finalResult.end());
        return finalResult;
    }
};