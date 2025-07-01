import java.util.Stack;

class Solution {
    public String RemoveDuplicates(String s) {
        Stack<Character> stack = new Stack<>();
        for (char c : s.toCharArray()) {
            if (!stack.isEmpty() && stack.peek() == c) {
                stack.pop();
            } else {
                stack.push(c);
            }
        }
        StringBuilder sb = new StringBuilder();
        for (char c : stack) {
            sb.append(c);
        }
        return sb.toString();
    }

    public static void main(String[] args) {
        Solution solution = new Solution();
        String s = "abbaca";
        String result = solution.RemoveDuplicates(s);
        System.out.println('"' + result + '"'); // Output: "ca"
    }
}
