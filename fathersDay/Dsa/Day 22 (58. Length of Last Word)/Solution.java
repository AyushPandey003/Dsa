class Solution {
    public int LengthOfLastWord(String s) {
        s = s.trim(); // Remove leading/trailing spaces
        if (s.isEmpty()) {
            return 0;
        }
        int lastSpaceIndex = s.lastIndexOf(' ');
        return s.length() - 1 - lastSpaceIndex;
    }

    public static void main(String[] args) {
        Solution solution = new Solution();
        String s = "Hello World";
        System.out.println(solution.LengthOfLastWord(s)); // Output: 5
    }
}
