import java.util.HashMap;
import java.util.Map;

class Solution {
    public int CenterOfStarGraph(int[][] edges) {
        Map<Integer, Integer> degree = new HashMap<>();
        for (int[] edge : edges) {
            degree.put(edge[0], degree.getOrDefault(edge[0], 0) + 1);
            degree.put(edge[1], degree.getOrDefault(edge[1], 0) + 1);
        }
        int n = edges.length + 1;
        for (Map.Entry<Integer, Integer> entry : degree.entrySet()) {
            if (entry.getValue() == n - 1) {
                return entry.getKey();
            }
        }
        return -1;
    }

    public static void main(String[] args) {
        Solution solution = new Solution();
        int[][] edges = {{1, 2}, {2, 3}, {4, 2}};
        int result = solution.CenterOfStarGraph(edges);
        System.out.println(result); // Output: 2
    }
}
