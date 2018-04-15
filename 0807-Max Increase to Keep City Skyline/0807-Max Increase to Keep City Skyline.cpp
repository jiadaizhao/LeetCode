class Solution {
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<int> maxRows(m), maxCols(n);
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                maxRows[i] = max(maxRows[i], grid[i][j]);
                maxCols[j] = max(maxCols[j], grid[i][j]);
            }
        }
        
        int sum = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                sum += min(maxRows[i] - grid[i][j], maxCols[j] - grid[i][j]);
            }
        }
        return sum;
    }
};
