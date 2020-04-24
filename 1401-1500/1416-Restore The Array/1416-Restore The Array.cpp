class Solution {
public:
    int numberOfArrays(string s, int k) {
        int MOD = 1e9 + 7, n = s.size();
        vector<int> dp(n + 1);
        dp[0] = 1;
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= min(i, 10); ++j) {
                if (s[i - j] == '0') {
                    continue;
                }
                long num = stol(s.substr(i - j, j));
                if (num >= 1 && num <= k) {
                    dp[i] = (dp[i] + dp[i - j]) % MOD;
                }
                else {
                    break;
                }
            }
        }
        
        return dp[n];
    }
};
