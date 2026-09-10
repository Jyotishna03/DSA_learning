class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char, int> f;
        
        // Count frequencies of each character
        for(int i = 0; i < s.size(); i++) {
            f[s[i]]++;
        }
        
        bool hasOdd = false;
        int res = 0;
        
        // Calculate the maximum palindrome length
        for(auto i : f){
            int val = i.second;
            if(val % 2 == 0) {
                res += val;
            } else {
                res += val - 1; // Add the maximum even part of the odd count
                hasOdd = true;  // Mark that we found an odd character
            }
        }
        
        // If there was at least one odd character, one can sit in the center
        if (hasOdd) {
            res += 1;
        }
        
        return res;
    }
};
