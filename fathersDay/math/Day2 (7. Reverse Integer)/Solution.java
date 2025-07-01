class Solution {
    public int reverse(int x) {
        long reversed_x = 0;
        int sign = (x < 0) ? -1 : 1;
        x = Math.abs(x);
        
        while (x > 0) {
            int digit = x % 10;
            reversed_x = reversed_x * 10 + digit;
            x /= 10;
        }
        
        reversed_x *= sign;
        
        if (reversed_x < Integer.MIN_VALUE || reversed_x > Integer.MAX_VALUE) {
            return 0;
        }
        
        return (int) reversed_x;
    }
}