class Solution {
public:
    int knightDialer(int N) {
        int MOD = 1e9 + 7;
        vector<long long> dp(10, 1);
        for (int i = 0; i < N - 1; ++i) {
            vector<long long> temp(10);
            temp[0] = (dp[4] + dp[6]) % MOD;
            temp[1] = (dp[6] + dp[8]) % MOD;
            temp[2] = (dp[7] + dp[9]) % MOD;
            temp[3] = (dp[4] + dp[8]) % MOD;
            temp[4] = (dp[0] + dp[3] + dp[9]) % MOD;
            // temp[5] = 0;
            temp[6] = (dp[0] + dp[1] + dp[7]) % MOD;
            temp[7] = (dp[2] + dp[6]) % MOD;
            temp[8] = (dp[1] + dp[3]) % MOD;
            temp[9] = (dp[2] + dp[4]) % MOD;
            dp = temp;
        }
        return accumulate(dp.begin(), dp.end(), 0LL) % MOD;
    }
};
