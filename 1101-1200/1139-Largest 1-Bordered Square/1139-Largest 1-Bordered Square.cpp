class Solution {
public:
    int largest1BorderedSquare(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> left(m, vector<int>(n)), top(m, vector<int>(n));
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1) {
                    left[i][j] = (j > 0) ? left[i][j - 1] + 1 : 1;
                    top[i][j] = (i > 0) ? top[i - 1][j] + 1 : 1;
                }
            }
        }

        int maxLen = 0;
        for (int i = m - 1; i >= 0; --i) {
            for (int j = n - 1; j >= 0; --j) {
                int candidate = min(left[i][j], top[i][j]);
                while (candidate > maxLen) {
                    if (left[i - candidate + 1][j] >= candidate &&
                        top[i][j - candidate + 1] >= candidate) {
                        maxLen = candidate;
                    }
                    --candidate;
                }
            }
        }

        return maxLen * maxLen;
    }
};
