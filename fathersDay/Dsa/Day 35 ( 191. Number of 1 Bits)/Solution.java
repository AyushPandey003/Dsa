class Solution {
    public int NumberOfoneBits(int n) {
        int count = 0;
        while (n != 0) {
            count += n & 1;
            n >>>= 1; // Use unsigned right shift
        }
        return count;
    }

    public static void main(String[] args) {
        Solution solution = new Solution();
        int n = 11; // Binary representation: 1011
        int result = solution.NumberOfoneBits(n);
        System.out.println(result); // Output: 3
    }
}
