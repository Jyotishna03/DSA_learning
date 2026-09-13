class Solution {
private:
    void dfs(std::vector<std::vector<char>>& grid, int r, int c, int rows, int cols) {
        // Boundary condition and water check
        if (r < 0 || c < 0 || r >= rows || c >= cols || grid[r][c] == '0') {
            return;
        }
        
        // Mark the current land cell as visited by sinking it
        grid[r][c] = '0';
        
        // Recursively visit all 4 adjacent neighbors
        dfs(grid, r + 1, c, rows, cols); // Down
        dfs(grid, r - 1, c, rows, cols); // Up
        dfs(grid, r, c + 1, rows, cols); // Right
        dfs(grid, r, c - 1, rows, cols); // Left
    }

public:
    int numIslands(std::vector<std::vector<char>>& grid) {
        if (grid.empty()) return 0;
        
        int rows = grid.size();
        int cols = grid[0].size();
        int island_count = 0;
        
        for (int r = 0; r < rows; ++r) {
            for (int c = 0; c < cols; ++c) {
                // If we hit unvisited land, it's a new island
                if (grid[r][c] == '1') {
                    island_count++;
                    // Sink the entire island using DFS
                    dfs(grid, r, c, rows, cols);
                }
            }
        }
        
        return island_count;
        
    }
};