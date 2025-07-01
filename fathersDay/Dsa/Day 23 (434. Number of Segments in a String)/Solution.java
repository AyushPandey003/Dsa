class Solution {
    public int NumberOfSegments(String s) {
        String trimmed = s.trim();
        if (trimmed.isEmpty()) {
            return 0;
        }
        return trimmed.split("\\s+").length;
    }

    public static void main(String[] args) {
        Solution solution = new Solution();
        String s = "Hello, my name is John";
        int result = solution.NumberOfSegments(s);
        System.out.println(result); // Output: 5
    }
}
