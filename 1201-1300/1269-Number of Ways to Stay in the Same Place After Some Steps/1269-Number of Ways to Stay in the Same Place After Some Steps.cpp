class Solution {
public:
    int numWays(int steps, int arrLen) {
        int sz = min(steps / 2 + 1, arrLen);
        vector<int> dp(sz);
        dp[0] = 1;
        int MOD = 1e9 + 7;
        for (int i = 0; i < steps; ++i) {
            vector<int> temp(sz);
            for (int j = 0; j < sz; ++j) {
                temp[j] = (((j > 0) ? dp[j - 1] : 0) +
                          (long)dp[j] + ((j < sz - 1) ? dp[j + 1] : 0)) % MOD;
            }
            swap(temp, dp);
        }
        
        return dp[0];
    }
};
