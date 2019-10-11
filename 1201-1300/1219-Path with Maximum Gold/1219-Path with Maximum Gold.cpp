class Solution {
public:
    int getMaximumGold(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int maxGold = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] > 0) {
                    maxGold = max(maxGold, dfs(grid, i, j));
                }
            }
        }

        return maxGold;
    }

private:
    int dfs(vector<vector<int>>& grid, int row, int col) {
        int m = grid.size(), n = grid[0].size();
        int orig = grid[row][col], gold = grid[row][col];
        grid[row][col] = 0;
        int dr[4] = {-1, 1, 0, 0};
        int dc[4] = {0, 0, -1, 1};
        for (int k = 0; k < 4; ++k) {
            int nr = row + dr[k];
            int nc = col + dc[k];
            if (nr >= 0 && nr < m && nc >= 0 && nc < n && grid[nr][nc] > 0) {
                gold = max(gold, orig + dfs(grid, nr, nc));
            }
        }

        grid[row][col] = orig;
        return gold;
    }
};
