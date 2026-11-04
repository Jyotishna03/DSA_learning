class Solution {
public:
    long long minOperations(vector<int>& nums, int x, int k) {
        int n = nums.size();
        
        // Step 1: Precompute the cost for each window of size x using dual multisets
        multiset<long long> lower, upper;
        long long lower_sum = 0, upper_sum = 0;

        auto balance = [&]() {
            if (lower.size() < upper.size()) {
                long long val = *upper.begin();
                upper.erase(upper.begin());
                upper_sum -= val;
                lower.insert(val);
                lower_sum += val;
            } else if (lower.size() > upper.size() + 1) {
                long long val = *lower.rbegin();
                lower.erase(prev(lower.end()));
                lower_sum -= val;
                upper.insert(val);
                upper_sum += val;
            }
        };

        vector<long long> cost(n - x + 1, 0);

        for (int i = 0; i < n; ++i) {
            if (lower.empty() || nums[i] <= *lower.rbegin()) {
                lower.insert(nums[i]);
                lower_sum += nums[i];
            } else {
                upper.insert(nums[i]);
                upper_sum += nums[i];
            }
            balance();

            if (i >= x) {
                long long out_val = nums[i - x];
                auto it = lower.find(out_val);
                if (it != lower.end()) {
                    lower.erase(it);
                    lower_sum -= out_val;
                } else {
                    it = upper.find(out_val);
                    if (it != upper.end()) {
                        upper.erase(it);
                        upper_sum -= out_val;
                    }
                }
                balance();
            }

            if (i >= x - 1) {
                long long median = *lower.rbegin();
                long long ops = (median * lower.size() - lower_sum) + (upper_sum - median * upper.size());
                cost[i - x + 1] = ops;
            }
        }

        // Step 2: Dynamic Programming with Space/Time Optimization
        // dp[j][i] = min operations to form j subarrays using prefix of length i
        const long long INF = 1e16;
        vector<vector<long long>> dp(k + 1, vector<long long>(n + 1, INF));
        
        for (int i = 0; i <= n; ++i) {
            dp[0][i] = 0;
        }

        for (int j = 1; j <= k; ++j) {
            long long best_prev = INF;
            for (int i = 1; i <= n; ++i) {
                // If we can form a window ending at or before i-1
                if (i >= x) {
                    best_prev = min(best_prev, dp[j - 1][i - x] + cost[i - x]);
                }
                dp[j][i] = min(dp[j][i - 1], best_prev);
            }
        }

        return dp[k][n];
    }
};