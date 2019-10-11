class Solution {
public:
    int countVowelPermutation(int n) {
        vector<long> dp(5, 1);
        int MOD = 1e9 + 7;
        for (int i = 0; i < n - 1; ++i) {
            vector<long> temp(5);
            temp[0] = (dp[1] + dp[2] + dp[4]) % MOD;
            temp[1] = (dp[0] + dp[2]) % MOD;
            temp[2] = (dp[1] + dp[3]) % MOD;
            temp[3] = dp[2];
            temp[4] = (dp[2] + dp[3]) % MOD;
            dp = temp;
        }

        int result = 0;
        for (long i : dp) {
            result = (result + i) % MOD;
        }

        return result;
    }
};
