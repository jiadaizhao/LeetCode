class Solution {
public:
    int surfaceArea(vector<vector<int>>& grid) {
        int total = 0;
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[i].size(); ++j) {
                if (grid[i][j] > 0) {
                    total += grid[i][j] * 4 + 2;
                    if (i > 0) {
                        total -= min(grid[i - 1][j], grid[i][j]) * 2;
                    }
                    if (j > 0) {
                        total -= min(grid[i][j - 1], grid[i][j]) * 2;
                    }
                }
            }
        }
        
        return total;
    }
};
