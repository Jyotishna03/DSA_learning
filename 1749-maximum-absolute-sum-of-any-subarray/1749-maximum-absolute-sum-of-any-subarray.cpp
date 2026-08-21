class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int maxEnding = nums[0];
        int minEnding = nums[0];
        int ans = abs(nums[0]);

        for (int i = 1; i < nums.size(); i++) {
            maxEnding = max(nums[i], maxEnding + nums[i]);
            minEnding = min(nums[i], minEnding + nums[i]);

            ans = max(ans, max(abs(maxEnding), abs(minEnding)));
        }

        return ans;
    }
};