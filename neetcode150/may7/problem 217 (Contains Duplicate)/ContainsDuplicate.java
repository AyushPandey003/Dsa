import java.util.HashMap;
import java.util.Map;


public class ContainsDuplicate {
 
public static class Solution {
    public boolean containsDuplicate(int[] nums) {
        Map<Integer, Integer> myCountArray = new HashMap<>();
        for (int i : nums) {
            if (myCountArray.containsKey(i)) {
                return true;
            }
            myCountArray.put(i, 1);
        }
        return false;
    }
}

public static void main(String[] args) {
    ContainsDuplicate.Solution solution = new ContainsDuplicate.Solution();
    int[] nums = {1, 2, 3, 1};
    System.out.println(solution.containsDuplicate(nums));

    int[] nums2 = {1, 2, 3, 4};
    System.out.println(solution.containsDuplicate(nums2)); 

    int[] nums3 = {1, 1, 1, 3, 3, 4, 3, 2, 4, 2};
    System.out.println(solution.containsDuplicate(nums3));
}
    
    }