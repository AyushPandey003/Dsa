import java.util.Arrays;
import java.util.Collections;
import java.util.List;

class Solution {
    public String ReverseWords(String s) {
        // Trim leading/trailing spaces and split by one or more spaces
        String[] words = s.trim().split("\\s+");
        List<String> wordList = Arrays.asList(words);
        Collections.reverse(wordList);
        return String.join(" ", wordList);
    }

    public static void main(String[] args) {
        Solution solution = new Solution();
        String words = "the sky is blue";
        String result = solution.ReverseWords(words);
        System.out.println('"' + result + '"'); // Output: "blue is sky the"
    }
}
