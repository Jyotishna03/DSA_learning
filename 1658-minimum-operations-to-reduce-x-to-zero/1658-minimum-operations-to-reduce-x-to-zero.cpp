class Solution {
public:
    int minOperations(vector<int>& nums, int x) {

        int n = nums.size();

        int total = 0;

        // Find total sum
        for(int num : nums) {
            total += num;
        }

        int target = total - x;

        // If target is negative,
        // we cannot make the required sum
        if(target < 0)
            return -1;

        int left = 0;
        int sum = 0;
        int longest = -1;

        // Sliding window
        for(int right = 0; right < n; right++) {

            sum += nums[right];

            // If sum becomes too large,
            // move left forward
            while(left <= right && sum > target) {
                sum -= nums[left];
                left++;
            }

            // Found a subarray with required sum
            if(sum == target) {
                longest = max(longest, right - left + 1);
            }
        }

        // No valid subarray
        if(longest == -1)
            return -1;

        return n - longest;
    }
};