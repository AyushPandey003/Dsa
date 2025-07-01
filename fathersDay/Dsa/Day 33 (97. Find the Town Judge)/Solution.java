class Solution {
    public int FindJudge(int n, int[][] trust) {
        if (n == 1 && trust.length == 0) {
            return 1;
        }
        
        int[] trustCount = new int[n + 1];
        int[] trustedBy = new int[n + 1];
        
        for (int[] pair : trust) {
            trustCount[pair[0]]++;
            trustedBy[pair[1]]++;
        }
        
        for (int i = 1; i <= n; ++i) {
            if (trustCount[i] == 0 && trustedBy[i] == n - 1) {
                return i;
            }
        }
        
        return -1;
    }

    public static void main(String[] args) {
        Solution solution = new Solution();
        int n = 3;
        int[][] trust = {{1, 2}, {2, 3}};
        int result = solution.FindJudge(n, trust);
        System.out.println(result); // Output: -1
    }
}
