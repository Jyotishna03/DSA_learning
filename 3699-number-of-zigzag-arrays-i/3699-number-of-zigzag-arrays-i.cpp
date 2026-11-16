class Solution {
public:
    int zigZagArrays(int n, int l, int r) {
        const int MOD = 1e9 + 7;
        int m = r - l + 1;
        
        // up[x]: ways ending at x where the last move went UP
        // down[x]: ways ending at x where the last move went DOWN
        vector<int> up(m, 1), down(m, 1);
        
        for (int step = 2; step <= n; ++step) {
            vector<int> next_up(m, 0), next_down(m, 0);
            
            // Prefix sum of down: next_up[y] = sum(down[0 ... y-1])
            long long pref = 0;
            for (int y = 0; y < m; ++y) {
                next_up[y] = pref;
                pref = (pref + down[y]) % MOD;
            }
            
            // Suffix sum of up: next_down[y] = sum(up[y+1 ... m-1])
            long long suff = 0;
            for (int y = m - 1; y >= 0; --y) {
                next_down[y] = suff;
                suff = (suff + up[y]) % MOD;
            }
            
            up = move(next_up);
            down = move(next_down);
        }
        
        long long ans = 0;
        for (int x = 0; x < m; ++x) {
            ans = (ans + up[x] + down[x]) % MOD;
        }
        
        return ans;
    }
};