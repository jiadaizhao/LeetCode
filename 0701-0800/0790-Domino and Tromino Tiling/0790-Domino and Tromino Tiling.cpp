class Solution {
public:
    int numTilings(int N) {
        int MOD = 1000000007;
        vector<int> dp(1 + N);
        dp[0] = 1;
        dp[1] = 1;
        dp[2] = 2;
        if (N <= 2) return dp[N];
        for (int i = 3; i <= N; ++i) {
            dp[i] = ((dp[i - 1] + dp[i - 1]) % MOD + dp[i - 3]) % MOD;
        }
        return dp[N];
    }
};
