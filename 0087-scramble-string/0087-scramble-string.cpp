class Solution {
private:
    unordered_map<string, bool> memo;

public:
    bool solve(string s1, string s2) {
        // Same string
        if (s1 == s2) return true;
        
        // Different lengths
        if (s1.size() != s2.size()) return false;

        int n = s1.size();

        // Check characters frequency (Pruning step)
        vector<int> count(26, 0);
        for (int i = 0; i < n; i++) {
            count[s1[i] - 'a']++;
            count[s2[i] - 'a']--;
        }
        for (int x : count) {
            if (x != 0) return false;
        }

        // Create a unique key for memoization
        string key = s1 + "_" + s2;
        if (memo.find(key) != memo.end()) {
            return memo[key];
        }

        // Try every possible split
        for (int i = 1; i < n; i++) {
            // Case 1: No swap
            // s1 -> [0..i-1] and [i..n-1]
            // s2 -> [0..i-1] and [i..n-1]
            if (solve(s1.substr(0, i), s2.substr(0, i)) && 
                solve(s1.substr(i), s2.substr(i))) {
                return memo[key] = true;
            }

            // Case 2: Swap
            // s1 -> [0..i-1] and [i..n-1]
            // s2 -> [n-i..n-1] and [0..n-i-1]
            if (solve(s1.substr(0, i), s2.substr(n - i)) && 
                solve(s1.substr(i), s2.substr(0, n - i))) {
                return memo[key] = true;
            }
        }

        return memo[key] = false;
    }

    bool isScramble(string s1, string s2) {
        memo.clear();
        return solve(s1, s2);
    }
};