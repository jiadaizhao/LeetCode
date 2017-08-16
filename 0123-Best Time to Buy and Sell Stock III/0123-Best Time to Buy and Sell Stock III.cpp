class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if (n == 0)
        {
            return 0;
        }

        int k = 2;
        vector<vector<int>> dp(1 + k, vector<int>(n));
        // dp[i][j] = max(dp[i][j - 1], max(dp[i - 1][m] + prices[j] - prices[m]))
        //          = max(dp[i][j - 1], prices[j] + max(dp[i - 1][m] - prices[m]))
        for (int i = 1; i <= k; ++i)
        {
            int localMax = dp[i - 1][0] - prices[0];
            for (int j = 1; j < n; ++j)
            {
                dp[i][j] = max(dp[i][j - 1], prices[j] + localMax);
                localMax = max(localMax, dp[i - 1][j] - prices[j]);
            }
        }
                
        return dp[k][n - 1];
    }
};
