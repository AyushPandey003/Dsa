class Solution {
    public boolean isPalindrome(String s) {
        return new StringBuilder(s).reverse().toString().equals(s);
    }

    public String FindFirstPalindromic(String[] words) {
        for (String word : words) {
            if (isPalindrome(word)) {
                return word;
            }
        }
        return "";
    }

    public static void main(String[] args) {
        Solution solution = new Solution();
        String[] words = {"abc", "car", "ada", "racecar", "cool"};
        String result = solution.FindFirstPalindromic(words);
        System.out.println('"' + result + '"'); // Output: "ada"
    }
}
