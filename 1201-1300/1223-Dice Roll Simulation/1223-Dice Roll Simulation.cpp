class Solution {
public:
    int dieSimulator(int n, vector<int>& rollMax) {
        int MOD = 1e9 + 7;
        vector<vector<long>> dp(n, vector<long>(7, 1));
        dp[0][6] = 6;
        for (int i = 1; i < n; ++i) {
            long total = 0;
            for (int j = 0; j < 6; ++j) {
                dp[i][j] = dp[i - 1][6];
                if (i > rollMax[j]) {
                    long reduction = (dp[i - rollMax[j] - 1][6] - dp[i - rollMax[j] - 1][j] + MOD) % MOD;
                    dp[i][j] = (dp[i][j] - reduction + MOD) % MOD;
                }
                else if (i == rollMax[j]) {
                    dp[i][j] = (dp[i][j] - 1 + MOD) % MOD;
                }
                total = (total + dp[i][j]) % MOD;
            }
            dp[i][6] = total;
        }

        return dp[n - 1][6];
    }
};
