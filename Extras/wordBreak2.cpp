// Given a string s and a dictionary of strings wordDict, add spaces in s to construct a sentence where each word is a valid dictionary word. Return all such possible sentences in any order.

// Note that the same word in the dictionary may be reused multiple times in the segmentation.

 

// Example 1:

// Input: s = "catsanddog", wordDict = ["cat","cats","and","sand","dog"]
// Output: ["cats and dog","cat sand dog"]
// Example 2:

// Input: s = "pineapplepenapple", wordDict = ["apple","pen","applepen","pine","pineapple"]
// Output: ["pine apple pen apple","pineapple pen apple","pine applepen apple"]
// Explanation: Note that you are allowed to reuse a dictionary word.
// Example 3:

// Input: s = "catsandog", wordDict = ["cats","dog","sand","and","cat"]
// Output: []
 

// Constraints:

// 1 <= s.length <= 20
// 1 <= wordDict.length <= 1000
// 1 <= wordDict[i].length <= 10
// s and wordDict[i] consist of only lowercase English letters.
// All the strings of wordDict are unique.

#include <vector>
#include <string>
#include <unordered_set>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> wordSet(wordDict.begin(), wordDict.end());
        unordered_map<int, vector<string>> memo;
        return wordBreakHelper(s, wordSet, 0, memo);
    }
    
private:
    vector<string> wordBreakHelper(const string& s, const unordered_set<string>& wordSet, int start, unordered_map<int, vector<string>>& memo) {
        if (memo.find(start) != memo.end()) {
            return memo[start];
        }
        
        vector<string> result;
        if (start == s.size()) {
            result.push_back("");
            return result;
        }
        
        for (int end = start + 1; end <= s.size(); ++end) {
            string word = s.substr(start, end - start);
            if (wordSet.find(word) != wordSet.end()) {
                vector<string> sublist = wordBreakHelper(s, wordSet, end, memo);
                for (const string& sub : sublist) {
                    result.push_back(word + (sub.empty() ? "" : " ") + sub);
                }
            }
        }
        
        memo[start] = result;
        return result;
    }
};
