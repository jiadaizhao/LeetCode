class Solution {
public:
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size(), count = 0;
        for (int i = 0; i < m - 2; ++i) {
            for (int j = 0; j < n - 2; ++j) {
                if (grid[i + 1][j + 1] == 5 && isMagic(grid, i, j)) {
                    ++count;
                }
            }
        }
        return count;
    }
    
private:
    bool isMagic(vector<vector<int>>& grid, int r, int c) {
        vector<int> count(10);
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                if (grid[r + i][c + j] < 1 || grid[r + i][c + j] > 9) {
                    return false;
                }
                if (++count[grid[r + i][c + j]] > 1) {
                    return false;
                }
            }
        }
        
        return grid[r][c] + grid[r][c + 1] + grid[r][c + 2] == 15 &&
               grid[r + 1][c] + grid[r + 1][c + 1] + grid[r + 1][c + 2] == 15 &&
               grid[r + 2][c] + grid[r + 2][c + 1] + grid[r + 2][c + 2] == 15 &&
               grid[r][c] + grid[r + 1][c] + grid[r + 2][c] == 15 &&
               grid[r][c + 1] + grid[r + 1][c + 1] + grid[r + 2][c + 1] == 15 &&
               grid[r][c + 2] + grid[r + 1][c + 2] + grid[r + 2][c + 2] == 15 &&
               grid[r][c] + grid[r + 1][c + 1] + grid[r + 2][c + 2] == 15 &&
               grid[r][c + 2] + grid[r + 1][c + 1] + grid[r + 2][c] == 15;
    }
};
