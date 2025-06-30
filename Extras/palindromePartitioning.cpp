// 131. Palindrome Partitioning
// Solved
// Medium
// Topics
// Companies
// Given a string s, partition s such that every 
// substring
//  of the partition is a 
// palindrome
// . Return all possible palindrome partitioning of s.

 

// Example 1:

// Input: s = "aab"
// Output: [["a","a","b"],["aa","b"]]
// Example 2:

// Input: s = "a"
// Output: [["a"]]
 

// Constraints:

// 1 <= s.length <= 16
// s contains only lowercase English letters.

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> result;
        vector<string> current;
        backtrack(result, current, s, 0);
        return result;
    }
    
private:
    // Utility function to check if a substring is a palindrome
    bool isPalindrome(const string &s, int start, int end) {
        while (start < end) {
            if (s[start] != s[end]) {
                return false;
            }
            start++;
            end--;
        }
        return true;
    }
    
    // Backtracking function to find all palindromic partitions
    void backtrack(vector<vector<string>> &result, vector<string> &current, const string &s, int start) {
        if (start >= s.length()) {
            result.push_back(current);
            return;
        }
        
        for (int end = start; end < s.length(); end++) {
            if (isPalindrome(s, start, end)) {
                current.push_back(s.substr(start, end - start + 1));
                backtrack(result, current, s, end + 1);
                current.pop_back();
            }
        }
    }
};

int main() {
    Solution solution;
    string s = "aab";
    vector<vector<string>> partitions = solution.partition(s);
    
    for (const auto &partition : partitions) {
        for (const auto &palindrome : partition) {
            cout << palindrome << " ";
        }
        cout << endl;
    }
    
    return 0;
}
