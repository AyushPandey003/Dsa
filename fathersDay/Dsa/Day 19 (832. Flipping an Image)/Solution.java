class Solution {
    public int[][] flipAndInvertImage(int[][] image) {
        for (int[] row : image) {
            int left = 0;
            int right = row.length - 1;
            while (left <= right) {
                // Swap and invert
                int temp = row[left] == 0 ? 1 : 0;
                row[left] = row[right] == 0 ? 1 : 0;
                row[right] = temp;
                left++;
                right--;
            }
        }
        return image;
    }

    public static void main(String[] args) {
        Solution solution = new Solution();
        int[][] image = {{1, 1, 0}, {1, 0, 1}, {0, 0, 0}};
        int[][] result = solution.flipAndInvertImage(image);
        for (int[] row : result) {
            for (int pixel : row) {
                System.out.print(pixel + " ");
            }
            System.out.println();
        }
        // Expected Output:
        // 1 0 0 
        // 0 1 0 
        // 1 1 1 
    }
}
