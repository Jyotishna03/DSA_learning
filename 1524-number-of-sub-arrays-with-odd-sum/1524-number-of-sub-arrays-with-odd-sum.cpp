class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        long long oddCount = 0;
        long long evenCount = 1; // Base case: prefix sum of 0 is even
        long long currentPrefixSum = 0;
        long long totalOddSubarrays = 0;
        int MOD = 1e9 + 7;

        for (int num : arr) {
            currentPrefixSum += num;

            if (currentPrefixSum % 2 != 0) {
                // Current prefix sum is odd, add count of previous even prefix sums
                totalOddSubarrays = (totalOddSubarrays + evenCount) % MOD;
                oddCount++;
            } else {
                // Current prefix sum is even, add count of previous odd prefix sums
                totalOddSubarrays = (totalOddSubarrays + oddCount) % MOD;
                evenCount++;
            }
        }

        return totalOddSubarrays;
    }
};