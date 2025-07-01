import java.math.BigInteger;

class Solution {
    public String GreatestCommonDivisor(String str1, String str2) {
        if (!(str1 + str2).equals(str2 + str1)) {
            return "";
        }
        int gcdLength = BigInteger.valueOf(str1.length()).gcd(BigInteger.valueOf(str2.length())).intValue();
        return str1.substring(0, gcdLength);
    }

    public static void main(String[] args) {
        Solution solution = new Solution();
        String str1 = "ABCABC";
        String str2 = "ABC";
        String result = solution.GreatestCommonDivisor(str1, str2);
        System.out.println(result); // Output: "ABC"
    }
}
