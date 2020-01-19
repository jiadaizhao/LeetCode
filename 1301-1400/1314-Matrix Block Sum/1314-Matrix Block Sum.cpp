class Solution {
public:
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int K) {
        int m = mat.size(), n = mat[0].size();
        vector<vector<int>> presum(1 + m, vector<int>(1 + n));
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                presum[i][j] = presum[i - 1][j] + presum[i][j - 1] - presum[i - 1][j - 1] + mat[i - 1][j - 1];
            }
        }
        
        vector<vector<int>> result(m, vector<int>(n));
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                int r1 = max(0, i - K), c1 = max(0, j - K);
                int r2 = min(m - 1, i + K), c2 = min(n - 1, j + K);
                result[i][j] = presum[r2 + 1][c2 + 1] - presum[r2 + 1][c1] - presum[r1][c2 + 1] + presum[r1][c1];
            }
        }

        return result;
    }
};
