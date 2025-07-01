class Solution {
    public boolean judgeSquareSum(int c) {
        long left = 0;
        long right = (long) Math.sqrt(c);

        while (left <= right) {
            long currentSum = left * left + right * right;
            if (currentSum == c) {
                return true;
            } else if (currentSum < c) {
                left++;
            } else {
                right--;
            }
        }
        return false;
    }
}
