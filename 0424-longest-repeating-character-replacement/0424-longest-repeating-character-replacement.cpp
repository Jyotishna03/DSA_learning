class Solution {
public:
    int characterReplacement(string s, int k) {

        unordered_map<char, int> mp;

        int low = 0;
        int res = 0;
        int maxFreq = 0;

        for(int high = 0; high < s.size(); high++) {

            mp[s[high]]++;

            maxFreq = max(maxFreq, mp[s[high]]);

            while((high - low + 1) - maxFreq > k) {

                mp[s[low]]--;

                low++;
            }
            int len = high - low + 1;

            res = max(res, len);
        }

        return res;
    }
};