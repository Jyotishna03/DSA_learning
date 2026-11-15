class Solution {
public:
    int maxBuilding(int n, vector<vector<int>>& restrictions) {
        // Building 1 must have height 0
        restrictions.push_back({1, 0});
        sort(restrictions.begin(), restrictions.end());
        
        // Ensure building n is included as the right boundary
        if (restrictions.back()[0] != n) {
            restrictions.push_back({n, n - 1});
        }
        
        int m = restrictions.size();
        
        // Pass 1: Propagate height limits from left to right
        for (int i = 1; i < m; ++i) {
            int dist = restrictions[i][0] - restrictions[i - 1][0];
            restrictions[i][1] = min(restrictions[i][1], restrictions[i - 1][1] + dist);
        }
        
        // Pass 2: Propagate height limits from right to left
        for (int i = m - 2; i >= 0; --i) {
            int dist = restrictions[i + 1][0] - restrictions[i][0];
            restrictions[i][1] = min(restrictions[i][1], restrictions[i + 1][1] + dist);
        }
        
        // Calculate the maximum possible height between every pair of adjacent restrictions
        int maxH = 0;
        for (int i = 1; i < m; ++i) {
            int id1 = restrictions[i - 1][0], h1 = restrictions[i - 1][1];
            int id2 = restrictions[i][0], h2 = restrictions[i][1];
            
            int dist = id2 - id1;
            int peak = max(h1, h2) + (dist - abs(h1 - h2)) / 2;
            maxH = max(maxH, peak);
        }
        
        return maxH;
    }
};