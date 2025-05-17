import java.util.*;

public class solution {

    public static List<List<Integer>> kSumRecursive(int[] nums, int target, int k) {
        List<List<Integer>> res = new ArrayList<>();
        Arrays.sort(nums);

        if (nums.length == 0 || nums[0] * k > target || nums[nums.length - 1] * k < target) {
            return res; 
        }
        if (k == 2) {
            return twoSum(nums, target);
        }

        for (int i = 0; i < nums.length; i++) {
            if (i == 0 || nums[i] != nums[i - 1]) { 
                int[] subArray = Arrays.copyOfRange(nums, i + 1, nums.length);
                for (List<Integer> subset : kSumRecursive(subArray, target - nums[i], k - 1)) {
                    List<Integer> newList = new ArrayList<>(subset);
                    newList.add(0, nums[i]); 
                    res.add(newList);
                }
            }
        }
        return res;
    }

    private static List<List<Integer>> twoSum(int[] nums, int target) {
        List<List<Integer>> res = new ArrayList<>();
        int left = 0, right = nums.length - 1;

        while (left < right) {
            int sum = nums[left] + nums[right];
            if (sum == target) {
                res.add(Arrays.asList(nums[left], nums[right]));
                while (left < right && nums[left] == nums[left + 1]) left++; 
                while (left < right && nums[right] == nums[right - 1]) right--; 
                left++;
                right--;
            } else if (sum < target) {
                left++;
            } else {
                right--;
            }
        }
        return res;
    }

    public static void main(String[] args) {
        int[] nums = {-1, -1, 2, 4, 5, 6, 7};
        int target = 0;
        int k = 3;

        List<List<Integer>> result = kSumRecursive(nums, target, k);
        System.out.println(result);
    }
}