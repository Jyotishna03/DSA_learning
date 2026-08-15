class Solution {
public:
   int slidingWindow(vector<int>& nums, int goal) {
        unordered_map<int, int>mp;

        if (goal < 0)
            return 0;

        int low = 0;
        int res = 0;
        int sum = 0;

        for(int high = 0; high < nums.size(); high++) {

            sum += nums[high];

            while(sum > goal) { 

                sum -= nums[low];

                low++;
            }
            res += high - low + 1;

           
        } 
        return res;

    
    }
    int numSubarraysWithSum(vector<int>& nums, int goal) {

        return slidingWindow(nums, goal) - slidingWindow(nums, goal - 1);
    }

};    