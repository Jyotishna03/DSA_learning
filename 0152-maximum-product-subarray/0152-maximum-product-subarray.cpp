class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int i = 0;
        int maxEnding = nums[0];
        int minEnding = nums[0];
        int res = nums[0];

        for(i = 1; i < nums.size(); i++){
            int v1 = nums[i];
            int v2 = minEnding * nums[i];
            int v3 = maxEnding * nums[i];

            maxEnding = max(v1, max(v2, v3));
            minEnding = min(v1, min(v2, v3));

            res = max(res, max(maxEnding, minEnding));
        }
        return res;
        
    }
};