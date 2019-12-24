class Solution {
public:
    int maxSideLength(vector<vector<int>>& mat, int threshold) {
        int m = mat.size(), n = mat[0].size();
        vector<vector<int>> presum(1 + m, vector<int>(1 + n));
        int maxLen = 0;
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                presum[i][j] = presum[i - 1][j] + presum[i][j - 1] - presum[i - 1][j - 1] + mat[i - 1][j - 1];
                if (i > maxLen && j > maxLen && 
                    presum[i][j] - presum[i - maxLen - 1][j] - presum[i][j - maxLen - 1] + presum[i - maxLen - 1][j - maxLen - 1] <= threshold) {
                    ++maxLen;
                }                    
            }
        }

        return maxLen;
    }
};
