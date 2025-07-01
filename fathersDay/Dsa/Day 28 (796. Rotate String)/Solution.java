class Solution {
    public boolean RotateString(String s, String goal) {
        if (s.length() != goal.length()) {
            return false;
        }
        String doubledS = s + s;
        return doubledS.contains(goal);
    }

    public static void main(String[] args) {
        Solution solution = new Solution();
        String s = "abcde";
        String goal = "cdeab";
        boolean result = solution.RotateString(s, goal);
        System.out.println(result); // Output: true
    }
}
