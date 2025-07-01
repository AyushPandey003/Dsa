import java.util.HashMap;
import java.util.Map;

class Solution {
    public int NumberOfSubstrings(String s) {
        Map<Character, Integer> count = new HashMap<>();
        int left = 0;
        int result = 0;
        
        for (int right = 0; right < s.length(); ++right) {
            count.put(s.charAt(right), count.getOrDefault(s.charAt(right), 0) + 1);
            
            while (count.getOrDefault('a', 0) > 0 && count.getOrDefault('b', 0) > 0 && count.getOrDefault('c', 0) > 0) {
                result += s.length() - right;
                count.put(s.charAt(left), count.get(s.charAt(left)) - 1);
                left++;
            }
        }
        
        return result;
    }

    public static void main(String[] args) {
        Solution solution = new Solution();
        String s = "abcabc";
        int result = solution.NumberOfSubstrings(s);
        System.out.println(result); // Output: 10
    }
}
