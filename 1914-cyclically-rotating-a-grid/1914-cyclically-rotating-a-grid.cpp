class Solution {
public:
    vector<vector<int>> rotateGrid(vector<vector<int>>& grid, int k) {

        int m = grid.size();
        int n = grid[0].size();

        int layers = min(m, n) / 2;

        for (int layer = 0; layer < layers; layer++) {

            vector<int> v;

            // Top row
            for (int j = layer; j < n - layer; j++)
                v.push_back(grid[layer][j]);

            // Right column
            for (int i = layer + 1; i < m - layer; i++)
                v.push_back(grid[i][n - layer - 1]);

            // Bottom row
            for (int j = n - layer - 2; j >= layer; j--)
                v.push_back(grid[m - layer - 1][j]);

            // Left column
            for (int i = m - layer - 2; i > layer; i--)
                v.push_back(grid[i][layer]);

            int len = v.size();
            int shift = k % len;

            // Put rotated values back
            int idx = shift;

            // Top row
            for (int j = layer; j < n - layer; j++) {
                grid[layer][j] = v[idx];
                idx = (idx + 1) % len;
            }

            // Right column
            for (int i = layer + 1; i < m - layer; i++) {
                grid[i][n - layer - 1] = v[idx];
                idx = (idx + 1) % len;
            }

            // Bottom row
            for (int j = n - layer - 2; j >= layer; j--) {
                grid[m - layer - 1][j] = v[idx];
                idx = (idx + 1) % len;
            }

            // Left column
            for (int i = m - layer - 2; i > layer; i--) {
                grid[i][layer] = v[idx];
                idx = (idx + 1) % len;
            }
        }

        return grid;
    }
};