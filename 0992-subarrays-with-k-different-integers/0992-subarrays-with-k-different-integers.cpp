class Solution {
public:
    int slidingWindow(vector<int>& nums, int k) {
        unordered_map<int, int>mp;
        int low = 0;
        int high = 0;
        int n = nums.size();
          
        int res = 0;

        while(high < n) {

            mp[nums[high]]++;

            while(mp.size() > k) {
                //shrink
                mp[nums[low]]--;
                if(mp[nums[low]] == 0 ){
                    mp.erase(nums[low]);
                }
                low++;
            
            }
            res += (high - low + 1); 
            high++;
        }
        return res;
        
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return slidingWindow(nums, k) - slidingWindow(nums, k-1);
    }
        
};