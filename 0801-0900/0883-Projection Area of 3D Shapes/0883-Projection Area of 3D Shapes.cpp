class Solution {
public:
    int projectionArea(vector<vector<int>>& grid) {
        int total = 0, N = grid.size();
        for (int i = 0; i < N; ++i) {
            int maxRow = 0, maxCol = 0;
            for (int j = 0; j < N; ++j) {
                if (grid[i][j] > 0) {
                    total += 1;
                    maxRow = max(maxRow, grid[i][j]);                    
                }
                maxCol = max(maxCol, grid[j][i]);
            }
            total += maxRow;
            total += maxCol;
        }
        return total;
    }
};
