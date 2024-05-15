#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>
#include <string>
using namespace std;
// The Solution class contains methods to merge accounts.
class Solution {
public:
    // The accountsMerge method merges the accounts.
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        unordered_map<string, string> parent;
        unordered_map<string, string> owner;
        unordered_map<string, set<string>> unions;

        // Initialize the parent and owner of each email.
        for (int i = 0; i < accounts.size(); i++) {
            for (int j = 1; j < accounts[i].size(); j++) {
                parent[accounts[i][j]] = accounts[i][j];
                owner[accounts[i][j]] = accounts[i][0];
            }
        }

        // Connect each pair of emails in each account.
        for (int i = 0; i < accounts.size(); i++) {
            string p = find(accounts[i][1], parent);
            for (int j = 2; j < accounts[i].size(); j++)
                parent[find(accounts[i][j], parent)] = p;
        }

        // Gather all emails in the same union.
        for (int i = 0; i < accounts.size(); i++) {
            for (int j = 1; j < accounts[i].size(); j++)
                unions[find(accounts[i][j], parent)].insert(accounts[i][j]);
        }

        // Prepare the result.
        vector<vector<string>> res;
        for (pair<string, set<string>> p : unions) {
            vector<string> emails(p.second.begin(), p.second.end());
            emails.insert(emails.begin(), owner[p.first]);
            res.push_back(emails);
        }

        return res;
    }

private:
    // The find method finds the parent of the given email.
    string find(string s, unordered_map<string, string>& p) {
        return p[s] == s ? s : find(p[s], p);
    }
};

int main() {
    Solution solution;
    vector<vector<string>> accounts = {
        {"John", "johnsmith@mail.com", "john00@mail.com"},
        {"John", "johnnybravo@mail.com"},
        {"John", "johnsmith@mail.com", "john_newyork@mail.com"},
        {"Mary", "mary@mail.com"}
    };

    // Merge the accounts and print the result.
    vector<vector<string>> mergedAccounts = solution.accountsMerge(accounts);
    for (const auto &account : mergedAccounts) {
        for (const auto &email : account) {
            cout << email << " ";
        }
        cout << endl;
    }

    return 0;
}
