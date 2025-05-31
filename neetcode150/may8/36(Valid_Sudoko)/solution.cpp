#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>
#include <string>
using namespace std;
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_set<string> seen;
        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                if (board[i][j] == '.') {
                    continue;
                }
                if (board[i][j] < '1' || board[i][j] > '9') {
                    return false;
                }
                if (board[i][j] != '.') {
                    string rowKey = "row" + to_string(i) + board[i][j];
                    string colKey = "col" + to_string(j) + board[i][j];
                    string boxKey = "box" + to_string(i / 3) + to_string(j / 3) + board[i][j];
                    if (seen.count(rowKey) || seen.count(colKey) || seen.count(boxKey)) {
                        return false;
                    }
                    seen.insert(rowKey);
                    seen.insert(colKey);
                    seen.insert(boxKey);
                }
            }
        }
        return true;
    }
};
int main() {
    Solution solution;
    vector<vector<char>> board = {
        {'5', '3', '.', '.', '7', '.', '.', '.', '.'},
        {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
        {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
        {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
        {'4', '.', '6', '8', '5', '3', '.', '.', '1'},
        {'7', '.', '.', '2', '4', '1', '9', '.', '.'},
        {'.', '6', '.', '.', '.', '2', '8', '4', '.'},
        {'.', '.', '2', '4', '1', '9', '.', '8', '.'},
        {'.', '8', '7', '9', '2', '5', '.', '.', '.'}
    };
    if (solution.isValidSudoku(board)) {
        cout << "true" << endl;
    } else {
        cout << "false" << endl;
    }
}