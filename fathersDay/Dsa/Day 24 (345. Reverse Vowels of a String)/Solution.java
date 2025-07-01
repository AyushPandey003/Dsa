import java.util.Arrays;
import java.util.HashSet;
import java.util.Set;

class Solution {
    public String ReverseVowels(String s) {
        Set<Character> vowels = new HashSet<>(Arrays.asList('a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'));
        char[] sChars = s.toCharArray();
        int left = 0, right = sChars.length - 1;

        while (left < right) {
            while (left < right && !vowels.contains(sChars[left])) {
                left++;
            }
            while (left < right && !vowels.contains(sChars[right])) {
                right--;
            }
            if (left < right) {
                char temp = sChars[left];
                sChars[left++] = sChars[right];
                sChars[right--] = temp;
            }
        }
        return new String(sChars);
    }

    public static void main(String[] args) {
        Solution solution = new Solution();
        String s = "hello";
        String result = solution.ReverseVowels(s);
        System.out.println('"' + result + '"'); // Output: "holle"
    }
}
