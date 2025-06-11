import java.util.Scanner;

public class Solution {
    public boolean isPalindrome(String s) {
        s = s.toLowerCase().replaceAll("[^a-z0-9]", "");
        System.out.println("Processed string: " + s);

        for (int i = 0, j = s.length() - 1; i < j; i++, j--) {
            if (s.charAt(i) != s.charAt(j)) {
                return false;
            }
        }
        return true;
    }

    public static void main(String[] args) {
        Solution solution = new Solution();
        String s;

        try (Scanner scanner = new Scanner(System.in)) {
            System.out.print("Enter a string: ");
            s = scanner.nextLine();
        }

        boolean result = solution.isPalindrome(s);
        System.out.println(result ? "The string is a palindrome." : "The string is not a palindrome.");
    }
}