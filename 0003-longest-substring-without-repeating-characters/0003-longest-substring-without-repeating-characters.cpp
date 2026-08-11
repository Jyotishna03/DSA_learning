class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        unordered_map<char, int> mp;

        int low = 0;
        int res = 0;

        for(int high = 0; high < s.size(); high++) {

            mp[s[high]]++;

            while(mp[s[high]] > 1) {

                mp[s[low]]--;

                if(mp[s[low]] == 0) {
                    mp.erase(s[low]);
                }

                low++;
            }

            int len = high - low + 1;

            res = max(res, len);
        }

        return res;
    }
};