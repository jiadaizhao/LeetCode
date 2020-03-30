class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        if (k >= n / 2) {
            int sum = 0;
            for (int i = 1; i < n; ++i) {
                int diff = prices[i] - prices[i - 1];
                if (diff > 0) {
                    sum += diff;
                }
            }
            
            return sum;
        }
        
        vector<vector<int>> dp(1 + k, vector<int>(n));
        // dp[i][j] = max(dp[i][j - 1], max(dp[i - 1][m] + prices[j] - prices[m]))
        //          = max(dp[i][j - 1], prices[j] + max(dp[i - 1][m] - prices[m]))
        for (int i = 1; i <= k; ++i) {
            int localMax = dp[i - 1][0] - prices[0];
            for (int j = 1; j < n; ++j) {
                dp[i][j] = max(dp[i][j - 1], prices[j] + localMax);
                localMax = max(localMax, dp[i - 1][j] - prices[j]);
            }
        }
                
        return dp[k][n - 1];        
    }
};

// Optimize space
class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        if (k >= n / 2) {
            int sum = 0;
            for (int i = 1; i < n; ++i) {
                int diff = prices[i] - prices[i - 1];
                if (diff > 0) {
                    sum += diff;
                }
            }
            
            return sum;
        }
        
        vector<int> dp(n);
        for (int i = 1; i <= k; ++i) {
            int localMax = dp[0] - prices[0];
            vector<int> temp(n);
            for (int j = 1; j < n; ++j) {
                temp[j] = max(temp[j - 1], prices[j] + localMax);
                localMax = max(localMax, dp[j] - prices[j]);
            }
            dp = temp;
        }
        
        return dp[n - 1];    
    }
};
