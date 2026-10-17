import java.util.*;

class Solution {
    public long minSumSquareDiff(int[] nums1, int[] nums2, int k1, int k2) {
        int n = nums1.length;
        long totalOps = (long) k1 + k2;
        
        // Max possible difference is 10^5 according to LeetCode constraints
        long[] count = new long[100001];
        int maxDiff = 0;
        
        for (int i = 0; i < n; i++) {
            int diff = Math.abs(nums1[i] - nums2[i]);
            count[diff]++;
            if (diff > maxDiff) {
                maxDiff = diff;
            }
        }
        
        // Greedily reduce from maxDiff down to 1
        for (int i = maxDiff; i > 0; i--) {
            if (count[i] > 0) {
                if (totalOps >= count[i]) {
                    // We can move all elements currently at diff 'i' down to diff 'i - 1'
                    totalOps -= count[i];
                    count[i - 1] += count[i];
                    count[i] = 0;
                } else {
                    // We can only move 'totalOps' elements down by 1
                    count[i] -= totalOps;
                    count[i - 1] += totalOps;
                    totalOps = 0;
                    break;
                }
            }
        }
        
        // If we still have leftover operations and everything is already reduced to 0, 
        // extra operations don't change the sum (since sum can't go below 0).
        if (totalOps > 0) {
            return 0;
        }
        
        // Calculate the final minimum sum of squared differences
        long minSumSqDiff = 0;
        for (int i = 1; i <= maxDiff; i++) {
            if (count[i] > 0) {
                minSumSqDiff += count[i] * (long) i * i;
            }
        }
        
        return minSumSqDiff;
    }
}