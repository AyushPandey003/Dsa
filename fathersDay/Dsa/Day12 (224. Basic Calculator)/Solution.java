import java.util.Stack;

class Solution {
    public int calculate(String s) {
        s = s.replace(" ", ""); // Remove spaces
        Stack<Integer> stack = new Stack<>();
        long num = 0;
        int sign = 1; // 1 for positive, -1 for negative
        int result = 0;
        
        for (int i = 0; i < s.length(); i++) {
            char c = s.charAt(i);
            if (Character.isDigit(c)) {
                num = num * 10 + (c - '0');
            } else if (c == '+') {
                result += sign * num;
                num = 0;
                sign = 1;
            } else if (c == '-') {
                result += sign * num;
                num = 0;
                sign = -1;
            } else if (c == '(') {
                stack.push(result);
                stack.push(sign);
                result = 0;
                sign = 1;
            } else if (c == ')') {
                result += sign * num;
                num = 0;
                result *= stack.pop(); // Pop sign
                result += stack.pop(); // Pop previous result
            }
        }
        result += sign * num;
        return result;
    }
}