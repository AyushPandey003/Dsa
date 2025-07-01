class Solution {
    public boolean isPrime(int n) {
        if (n < 2) {
            return false;
        }
        for (int i = 2; i <= Math.sqrt(n); ++i) {
            if (n % i == 0) {
                return false;
            }
        }
        return true;
    }

    public int countSetBits(int n) {
        int count = 0;
        while (n > 0) {
            n &= (n - 1);
            count++;
        }
        return count;
    }

    public int PrimeSetBits(int left, int right) {
        int count = 0;
        for (int num = left; num <= right; ++num) {
            if (isPrime(countSetBits(num))) {
                count++;
            }
        }
        return count;
    }

    public static void main(String[] args) {
        Solution solution = new Solution();
        int left = 6;
        int right = 10;
        int result = solution.PrimeSetBits(left, right);
        System.out.println(result); // Output: 4
    }
}
