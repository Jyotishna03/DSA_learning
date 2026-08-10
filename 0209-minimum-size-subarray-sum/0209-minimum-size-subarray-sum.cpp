class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {

        int n = nums.size();

        int high = 0;
        int low = 0;
        int res = INT_MAX;
        int sum = 0;

        while(high < n) {

            // Add current element
            sum = sum + nums[high];

            // Shrink window while sum >= target
            while(sum >= target) {

                int len = high - low + 1;

                res = min(res, len);

                sum = sum - nums[low];

                low++;
            }

            // Expand window
            high++;
        }

        // No valid subarray found
        if(res == INT_MAX)
            return 0;

        return res;
    }
};