class Solution{
    public int LongestValidParentheses(String s) {
        int maxLength = 0;
        int stack[] = new int[s.length()];
        int top = -1;
        int lastInvalid = -1;
        for (int i = 0; i < s.length(); i++) {
            char c = s.charAt(i);
            if (c == '(') {
                stack[++top] = i; 
            } else {
                if (top == -1) {
                    lastInvalid = i; 
                } else {
                    top--; 
                    if (top == -1) {
                        maxLength = Math.max(maxLength, i - lastInvalid); 
                    } else {
                        maxLength = Math.max(maxLength, i - stack[top]);
                    }
                }
            }
        }

        
        return maxLength;
    }
    public static void main(String[] args) {
        Solution solution = new Solution();
        String s = ")(";
        int result = solution.LongestValidParentheses(s);
        System.out.println("Longest valid parentheses length: " + result); 
    }
}