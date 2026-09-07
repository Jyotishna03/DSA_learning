class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char, int> have;
        unordered_map<char, int> need;

        for(char c : ransomNote) {
            need[c]++;
        }

        for(char c : magazine) {
            have[c]++;
        }

        for(auto it : need) {
            char c = it.first;
            int required = it.second;

            if(have[c] < required) {
                return false;
            }
        }

        return true;
    }
};