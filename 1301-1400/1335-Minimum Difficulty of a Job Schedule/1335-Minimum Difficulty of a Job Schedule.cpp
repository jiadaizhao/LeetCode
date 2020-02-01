class Solution {
public:
    int minDifficulty(vector<int>& jobDifficulty, int d) {
        int n = jobDifficulty.size();
        int INTMAX = 1e9;
        if (n < d) {
            return -1;
        }
        vector<int> dp(1 + n, INTMAX);
        dp[0] = 0;
        for (int k = 1; k <= d; ++k) {
            for (int j = n; j >= k; --j) {
                dp[j] = INTMAX;
                int maxDiff = 0;
                for (int i = j - 1; i >= k - 1; --i) {
                    maxDiff = max(maxDiff, jobDifficulty[i]);
                    dp[j] = min(dp[j], dp[i] + maxDiff);
                }
            }
        }
        
        return (dp[n] < INTMAX) ? dp[n] : -1;
    }
};
