class Solution {
public:
    int numMusicPlaylists(int N, int L, int K) {
        vector<vector<long long>> dp(1 + L, vector<long long>(1 + N));
        dp[0][0] = 1;
        int MOD = 1000000007;
        for (int i = 1; i <= L; ++i) {
            for (int j = 1; j <= N; ++j) {
                dp[i][j] = dp[i - 1][j - 1] * (N - j + 1) % MOD;
                if (j > K) {
                    dp[i][j] = (dp[i][j] + dp[i - 1][j] * (j - K)) % MOD;
                }
            }
        }
        return dp[L][N];
    }
};
