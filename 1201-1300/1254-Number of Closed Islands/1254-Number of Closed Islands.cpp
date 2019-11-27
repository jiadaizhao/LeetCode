class Solution {
public:
    int closedIsland(vector<vector<int>>& grid) {        
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[i].size(); ++j) {
                if (grid[i][j] == 0 && (i == 0 || i == grid.size() - 1 || j == 0 || j == grid[i].size() - 1)) {
                    dfs(grid, i, j, 1);
                }
            }
        }
        
        int count = 0;
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[i].size(); ++j) {
                if (grid[i][j] == 0) {
                    ++count;
                    dfs(grid, i, j, 1);
                }
            }
        }
        
        return count;
    }
    
private:
    void dfs(vector<vector<int>>& grid, int row, int col, int val) {
        if (row < 0 || row >= grid.size() || col < 0 || col >= grid[0].size() || grid[row][col] == val) {
            return;
        }
        
        grid[row][col] = val;
        dfs(grid, row - 1, col, val);
        dfs(grid, row + 1, col, val);
        dfs(grid, row, col - 1, val);
        dfs(grid, row, col + 1, val);
    }
};
