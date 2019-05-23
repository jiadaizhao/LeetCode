class Solution {
public:
    int tallestBillboard(vector<int>& rods) {
        int maxH = accumulate(rods.begin(), rods.end(), 0) / 2;
        // Multiply each rod with 1, -1, 0, then sum up,
        // dp[i][j]: max sum of positive nums when i rods can make sum of j 
        vector<vector<int>> dp(2, vector<int>(maxH * 2 + 1, -1));
        dp[0][maxH] = 0;
        for (int i = 0; i < rods.size(); ++i) {
            for (int j = 0; j < dp[0].size(); ++j) {
                if (j - rods[i] >= 0 && dp[i & 1][j - rods[i]] != -1) {
                    dp[(i + 1) & 1][j] = max(dp[(i + 1) & 1][j], dp[i & 1][j - rods[i]] + rods[i]);
                }
                if (j + rods[i] < dp[0].size() && dp[i & 1][j + rods[i]] != -1) {
                    dp[(i + 1) & 1][j] = max(dp[(i + 1) & 1][j], dp[i & 1][j + rods[i]]);
                }
                dp[(i + 1) & 1][j] = max(dp[(i + 1) & 1][j], dp[i & 1][j]);
            }
        }
        
        return dp[rods.size() & 1][maxH];
    }
};
