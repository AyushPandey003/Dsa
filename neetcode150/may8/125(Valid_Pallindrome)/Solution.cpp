#include <string>
#include <iostream>
using namespace std;
class Solution{
    public:
    bool isPalindrome(string s) {
       s=s.substr(0, s.find_last_not_of(" ")+1);
       cout<<s<<endl;
       return true; 
    };
    };

    int main() {
        Solution sol;
        string input;
        cout << "Enter a string: ";
        getline(cin, input);
        bool result = sol.isPalindrome(input);
        cout << (result ? "Palindrome" : "Not Palindrome") << endl;
        return 0;
    }
