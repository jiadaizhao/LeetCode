class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        vector<int> dp(1 + n);
        int total = 0;
        for (int i = 0; i < m; ++i) {
            vector<int> temp(1 + n);
            for (int j = 1; j <= n; ++j) {
                if (matrix[i][j - 1] == 1) {
                    temp[j] = 1 + min({dp[j - 1], dp[j], temp[j - 1]});
                    total += temp[j];
                }
            }
            dp = move(temp);
        }
        
        return total;
    }
};
