class Solution {
public:
    vector<vector<int>> colorBorder(vector<vector<int>>& grid, int r0, int c0, int color) {
        dfs(grid, r0, c0, grid[r0][c0]);
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[0].size(); ++j) {
                if (grid[i][j] < 0) {
                    grid[i][j] = color;
                }
            }
        }
        return grid;
    }
    
private:
    void dfs(vector<vector<int>>& grid, int r, int c, int color) {
        grid[r][c] = -color;
        static int dr[4] = {-1, 1, 0, 0};
        static int dc[4] = {0, 0, -1, 1};
        for (int k = 0; k < 4; ++k) {
            int nr = r + dr[k];
            int nc = c + dc[k];
            if (nr >= 0 && nr < grid.size() && nc >= 0 && nc < grid[0].size() && grid[nr][nc] == color) {
                dfs(grid, nr, nc, color);
            }
        }
        
        if (r > 0 && r < grid.size() - 1&& c > 0 && c < grid[0].size() - 1 && abs(grid[r-1][c]) == color &&
            abs(grid[r+1][c]) == color && abs(grid[r][c-1]) == color && abs(grid[r][c+1]) == color) {
            grid[r][c] = color;
        }
    }
};
