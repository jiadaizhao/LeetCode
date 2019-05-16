class Solution {
public:
    int numPermsDISequence(string S) {
        int n = S.size();
        int MOD = 1e9 + 7;
        vector<vector<int>> dp(n + 2, vector<int>(n + 2));
        for (int j = 0; j < n + 2; ++j) {
            dp[1][j] = 1;
        }
        
        for (int i = 2; i < n + 2; ++i) {
            for (int j = 0; j < i; ++j) {
                if (S[i - 2] == 'D') {
                    if (j > 0) {
                        dp[i][j] = (dp[i][j - 1] + (dp[i - 1][i - 1] - dp[i - 1][j - 1] + MOD) % MOD) % MOD;
                    }
                    else {
                        dp[i][j] = dp[i - 1][i - 1];
                    }
                }
                else if (j > 0) {
                    dp[i][j] = (dp[i][j - 1] + dp[i - 1][j - 1]) % MOD;
                }
            }
            dp[i][i] = dp[i][i - 1];
        }
        
        return dp[n + 1][n];
    }
};
