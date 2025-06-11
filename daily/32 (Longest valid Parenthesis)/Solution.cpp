#include <iostream>
using namespace std;

class Solution {
public:
    int longestValidParentheses(string s) {
        int maxLength = 0;
        int left = 0, right = 0;
        for (char c : s) {
            if (c == '(') {
                left++;
            } else {
                right++;
            }
            if (left == right) {
                maxLength = max(maxLength, 2 * right);
            } else if (right > left) {
                left = right = 0; 
            }
        }
        left = right = 0;
        for (int i = s.size() - 1; i >= 0; i--) {
            if (s[i] == ')') {
                right++;
            } else {
                left++;
            }
            if (left == right) {
                maxLength = max(maxLength, 2 * left);
            } else if (left > right) {
                left = right = 0; 
            }
        }

        return maxLength;
    }
};

int main() {
    Solution solution;
    string s = "((";
    cout << "Longest valid parentheses length: " << solution.longestValidParentheses(s) << endl;
    return 0;
}