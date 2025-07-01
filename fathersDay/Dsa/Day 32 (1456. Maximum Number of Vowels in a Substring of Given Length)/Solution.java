import java.util.HashSet;
import java.util.Set;

class Solution {
    public int MaximumVowels(String s, int k) {
        Set<Character> vowels = new HashSet<>();
        vowels.add('a');
        vowels.add('e');
        vowels.add('i');
        vowels.add('o');
        vowels.add('u');

        int maxVowels = 0;
        int currentVowels = 0;

        for (int i = 0; i < s.length(); i++) {
            if (i >= k) {
                if (vowels.contains(s.charAt(i - k))) {
                    currentVowels--;
                }
            }
            if (vowels.contains(s.charAt(i))) {
                currentVowels++;
            }
             if (i >= k - 1) {
                maxVowels = Math.max(maxVowels, currentVowels);
            }
        }

        return maxVowels;
    }

    public static void main(String[] args) {
        Solution solution = new Solution();
        String s = "abciiidef";
        int k = 3;
        int result = solution.MaximumVowels(s, k);
        System.out.println(result); // Output: 3
    }
}
