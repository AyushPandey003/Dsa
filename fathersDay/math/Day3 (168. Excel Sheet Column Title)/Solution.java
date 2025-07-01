class Solution {
    public String convertToTitle(int n) {
        StringBuilder result = new StringBuilder();
        while (n > 0) {
            n--; // Adjust n to be 0-indexed (A=0, B=1, ..., Z=25)
            int remainder = n % 26;
            result.append((char)('A' + remainder));
            n /= 26;
        }
        return result.reverse().toString();
    }
}
