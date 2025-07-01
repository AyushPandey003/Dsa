class Solution {
public:
    int reverse(int x) {
        long reversed_x = 0;
        int sign = (x < 0) ? -1 : 1;
        x = abs(x);
        
        while (x > 0) {
            int digit = x % 10;
            reversed_x = reversed_x * 10 + digit;
            x /= 10;
        }
        
        reversed_x *= sign;
        
        if (reversed_x < -2147483648 || reversed_x > 2147483647) { // -2^31 and 2^31 - 1
            return 0;
        }
        
        return (int) reversed_x;
    }
};