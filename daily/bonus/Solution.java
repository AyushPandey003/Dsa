// import java.util.*;

// public class Solution {

//     public static int[] countTripletsModulo(int[] arr, int B) {
//         int[] freq = new int[B];
//         for (int num : arr) {
//             freq[num % B]++;
//         }

//         int[] res = new int[B];

//         for (int i = 0; i < B; i++) {
//             for (int j = i; j < B; j++) {
//                 for (int k = j; k < B; k++) {
//                     int mod = (i + j + k) % B;

//                     // Case 1: All mods same (i == j == k)
//                     if (i == j && j == k) {
//                         if (freq[i] >= 3) {
//                             res[mod] += (freq[i] * (freq[i] - 1) * (freq[i] - 2)) / 6;
//                         }
//                     }

//                     // Case 2: Two mods equal
//                     else if (i == j && j != k) {
//                         if (freq[i] >= 2 && freq[k] >= 1) {
//                             res[mod] += ((freq[i] * (freq[i] - 1)) / 2) * freq[k];
//                         }
//                     } else if (i == k && j != i) {
//                         if (freq[i] >= 2 && freq[j] >= 1) {
//                             res[mod] += ((freq[i] * (freq[i] - 1)) / 2) * freq[j];
//                         }
//                     } else if (j == k && i != j) {
//                         if (freq[j] >= 2 && freq[i] >= 1) {
//                             res[mod] += ((freq[j] * (freq[j] - 1)) / 2) * freq[i];
//                         }
//                     }

//                     // Case 3: All mods different
//                     else {
//                         if (i < j && j < k) {
//                             res[mod] += freq[i] * freq[j] * freq[k];
//                         }
//                     }
//                 }
//             }
//         }

//         return res;
//     }

//     public static void main(String[] args) {
//         int[] arr = {4, 8, 9, 8, 4, 2, 1, 3, 5, 6};
//         int B = 3;

//         int[] result = countTripletsModulo(arr, B);
//         System.out.println(Arrays.toString(result)); // Output: [2, 2, 0, 0, 0]
//     }
// }


import java.util.*;

public class Solution {
    public static void main(String[] args) {
        int[] nums = {4, 8, 9, 8, 4, 2, 1, 3, 5, 6};
        int b = 3;

        int[] count = new int[b];
        for (int num : nums) {
            count[num % b]++;
        }

        int[] freq = new int[b]; // freq[r] = # of triplets with sum % b == r

        for (int i = 0; i < b; i++) {
            for (int j = i; j < b; j++) {
                for (int k = j; k < b; k++) {
                    int modSum = (i + j + k) % b;

                    long ways = 0;

                    if (i == j && j == k) {
                        // All same
                        if (count[i] >= 3)
                            ways = count[i] * (count[i] - 1L) * (count[i] - 2L) / 6;
                    } else if (i == j && j != k) {
                        // i == j != k
                        if (count[i] >= 2)
                            ways = count[i] * (count[i] - 1L) / 2 * count[k];
                    } else if (i != j && j == k) {
                        // j == k != i
                        if (count[j] >= 2)
                            ways = count[j] * (count[j] - 1L) / 2 * count[i];
                    } else if (i == k && i != j) {
                        // i == k != j
                        if (count[i] >= 2)
                            ways = count[i] * (count[i] - 1L) / 2 * count[j];
                    } else {
                        // All different
                        ways = (long) count[i] * count[j] * count[k];
                    }

                    freq[modSum] += ways;
                }
            }
        }

        // Print the result
        System.out.println("Optimized Frequency of (sum % " + b + "): " + Arrays.toString(freq));
        }
}