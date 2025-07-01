class Solution {
    public String makeSmallestPalindrome(String s) {
        char[] sArray = s.toCharArray();
        int left = 0;
        int right = sArray.length - 1;
        while (left < right) {
            if (sArray[left] != sArray[right]) {
                if (sArray[left] < sArray[right]) {
                    sArray[right] = sArray[left];
                } else {
                    sArray[left] = sArray[right];
                }
            }
            left++;
            right--;
        }
        return new String(sArray);
    }

    public static void main(String[] args) {
        Solution solution = new Solution();
        String s = "egcfe";
        System.out.println(solution.makeSmallestPalindrome(s)); // Output: "efcfe"
    }
}
