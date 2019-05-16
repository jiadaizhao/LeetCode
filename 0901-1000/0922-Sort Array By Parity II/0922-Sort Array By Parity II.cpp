class Solution {
public:
    int threeSumMulti(vector<int>& A, int target) {
        vector<vector<int>> dp(1 + target, vector<int>(4));
        int MOD = 1000000007;
        dp[0][0] = 1;
        for (int i = 0; i < A.size(); ++i) {
            for (int j = target; j >= A[i]; --j) {
                for (int k = 3; k >= 1; --k) {
                    dp[j][k] = (dp[j][k] + dp[j - A[i]][k - 1]) % MOD;
                }
            }
        }
        return dp[target][3];
    }
};
