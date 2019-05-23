class Solution {
public:
    int uniquePathsIII(vector<vector<int>>& grid) {
        int total = 0, sr = 0, sc = 0, empty = 1;
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[i].size(); ++j) {
                if (grid[i][j] == 1) {
                    sr = i;
                    sc = j;
                }
                else if (grid[i][j] == 0) {
                    ++empty;
                }
            }
        }
        dfs(grid, sr, sc, empty, total);
        return total;
    }

private:
    int dr[4] = {-1, 1, 0, 0};
    int dc[4] = {0, 0, -1, 1};
    void dfs(vector<vector<int>>& grid, int row, int col, int empty, int& total) {
        if (grid[row][col] == 2) {
            if (empty == 0) {
                ++total;
            }
            return;
        }

        grid[row][col] = -1;
        --empty;
        for (int k = 0; k < 4; ++k) {
            int nr = row + dr[k];
            int nc = col + dc[k];
            if (nr >= 0 && nr < grid.size() && nc >= 0 && nc < grid[0].size() && grid[nr][nc] != -1) {
                dfs(grid, nr, nc, empty, total);
            }
        }
        ++empty;
        grid[row][col] = 0;
    }
};
