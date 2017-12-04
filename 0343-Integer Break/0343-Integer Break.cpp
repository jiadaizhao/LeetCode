class Solution {
public:
    int integerBreak(int n) {
        vector<int> dp(1 + n);
        dp[1] = 1;
        
        for (int j = 2; j <= n; ++j) {
            for (int i = j - 1; i >= 1; --i) {
                dp[j] = max(dp[j], max(i, dp[i]) * max(j - i, dp[j - i]));
            }
        }
        
        return dp[n];
    }
};
