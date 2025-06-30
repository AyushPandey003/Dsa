public class Solution{
    public String LongestHappyPrefix(String s) {
        int n = s.length();
        int[] lps = new int[n];
        int len = 0;
        for (int i = 1; i < n; i++) {
            if (s.charAt(i) == s.charAt(len)) {
                len++;
                lps[i] = len;
            } else if (len != 0) {
                len = lps[len - 1];
                i--;
            } else {
                lps[i] = 0;
            }
        }
        return s.substring(0, lps[n - 1]);
    }
    public static void main(String[] args) {
        Solution solution = new Solution();
        String s = "ababab";
        System.out.println("Longest Happy Prefix: " + solution.LongestHappyPrefix(s));
    }
}


// class Main{
//     public static void main(String args[]){
//         int var1=5;
//         int var2=10;
//         if ((var2==10) && (var1==5)) {
//             System.out.println("Both conditions are true");
//         } else {
//             System.out.println("At least one condition is false");
//         }
//     }
// }