#include <string>
#include <stack>
#include <algorithm>
#include <vector>

class Solution {
public:
    int calculate(std::string s) {
        // Remove spaces from the string
        s.erase(std::remove(s.begin(), s.end(), ' '), s.end());

        std::stack<int> st;
        long long currentNum = 0;
        int sign = 1; // 1 for positive, -1 for negative
        int result = 0;

        for (int i = 0; i < s.length(); ++i) {
            char c = s[i];

            if (isdigit(c)) {
                currentNum = currentNum * 10 + (c - '0');
            } else if (c == '+') {
                result += sign * currentNum;
                currentNum = 0;
                sign = 1;
            } else if (c == '-') {
                result += sign * currentNum;
                currentNum = 0;
                sign = -1;
            } else if (c == '(') {
                st.push(result);
                st.push(sign);
                result = 0;
                sign = 1;
            } else if (c == ')') {
                result += sign * currentNum;
                currentNum = 0;
                result *= st.top(); // Pop sign before parenthesis
                st.pop();
                result += st.top(); // Pop previous result
                st.pop();
            }
        }
        
        // Add the last number if any
        result += sign * currentNum;
        
        return result;
    }
};