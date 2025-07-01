#include <string>
#include <algorithm> // Required for std::reverse

class Solution {
public:
    std::string convertToTitle(int n) {
        std::string result = "";
        while (n > 0) {
            n--; // Adjust n to be 0-indexed (A=0, B=1, ..., Z=25)
            int remainder = n % 26;
            result += (char)('A' + remainder);
            n /= 26;
        }
        std::reverse(result.begin(), result.end());
        return result;
    }
};
