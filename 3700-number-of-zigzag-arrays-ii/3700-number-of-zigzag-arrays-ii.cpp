class Solution {
public:
    int zigZagArrays(int n, int l, int r) {
        int m = r - l + 1;
        if (n == 1) return m;
        
        long long MOD = 1e9 + 7;
        int dim = 2 * m;
        
        // Helper function for matrix multiplication
        auto multiply = [&](const vector<vector<long long>>& A, const vector<vector<long long>>& B) {
            int sz = A.size();
            vector<vector<long long>> C(sz, vector<long long>(sz, 0));
            for (int i = 0; i < sz; ++i) {
                for (int k = 0; k < sz; ++k) {
                    if (A[i][k] == 0) continue;
                    for (int j = 0; j < sz; ++j) {
                        C[i][j] = (C[i][j] + A[i][k] * B[k][j]) % MOD;
                    }
                }
            }
            return C;
        };
        
        // Helper function for matrix exponentiation
        auto power = [&](vector<vector<long long>> base, long long exp) {
            int sz = base.size();
            vector<vector<long long>> res(sz, vector<long long>(sz, 0));
            for (int i = 0; i < sz; ++i) res[i][i] = 1;
            while (exp > 0) {
                if (exp % 2 == 1) res = multiply(res, base);
                base = multiply(base, base);
                exp /= 2;
            }
            return res;
        };
        
        // Build transition matrix T of size 2m x 2m
        // Indices 0 to m-1 represent 'up' states for values l to r
        // Indices m to 2m-1 represent 'down' states for values l to r
        vector<vector<long long>> T(dim, vector<long long>(dim, 0));
        
        for (int x = 0; x < m; ++x) {
            // From up, x -> we need down, y where y < x
            for (int y = 0; y < x; ++y) {
                T[m + y][x] = 1; // transition from up, x to down, y
            }
            // From down, x -> we need up, y where y > x
            for (int y = x + 1; y < m; ++y) {
                T[y][m + x] = 1; // transition from down, x to up, y
            }
        }
        
        // Compute T^(n-1)
        vector<vector<long long>> Tn_1 = power(T, n - 1);
        
        // Initial state vector: all 1s (since any starting value in [l, r] is valid for n=1)
        // Sum all entries in Tn_1
        long long ans = 0;
        for (int i = 0; i < dim; ++i) {
            for (int j = 0; j < dim; ++j) {
                ans = (ans + Tn_1[i][j]) % MOD;
            }
        }
        
        return ans;
    }
};