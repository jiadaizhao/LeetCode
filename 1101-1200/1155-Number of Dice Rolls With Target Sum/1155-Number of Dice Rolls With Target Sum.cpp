class Solution {
public:
    int numRollsToTarget(int d, int f, int target) {
        vector<int> dp(1 + target);
        dp[0] = 1;
        int MOD = 1e9 + 7;
        for (int i = 1; i <= d; ++i) {
            vector<int> temp(1 + target);
            for (int j = 1; j <= target; ++j) {
                for (int k = 1; k <= min(f, j); ++k) {
                    temp[j] = (temp[j] + dp[j - k]) % MOD;
                }
            }
            swap(dp, temp);
        }
        
        return dp[target];
    }
};
