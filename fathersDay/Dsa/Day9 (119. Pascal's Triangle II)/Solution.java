import java.util.ArrayList;
import java.util.List;

class Solution {
    public List<Integer> getRow(int rowIndex) {
        if (rowIndex < 0) {
            return new ArrayList<>(); // Return an empty list for negative rowIndex
        }
        
        // Initialize a list of lists to store the triangle up to rowIndex
        // Each row i will have i+1 elements
        List<List<Integer>> triangle = new ArrayList<>();
        
        for (int i = 0; i <= rowIndex; i++) {
            List<Integer> row = new ArrayList<>();
            for (int j = 0; j <= i; j++) {
                if (j == 0 || j == i) {
                    row.add(1); // First and last elements of each row are 1
                } else {
                    // Each element is the sum of the two elements directly above it
                    row.add(triangle.get(i - 1).get(j - 1) + triangle.get(i - 1).get(j));
                }
            }
            triangle.add(row);
        }
        
        return triangle.get(rowIndex);
    }
}