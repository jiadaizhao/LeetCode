class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        int n = piles.size();
        int sum = accumulate(piles.begin(), piles.end(), 0);
        
        vector<vector<int>> dp(n, vector<int>(n));
        for (int i = 0; i < n; ++i) {
            dp[i][i] = piles[i];
            if (i < n - 1) {
                dp[i][i + 1] = max(piles[i], piles[i + 1]);
            }
        }
        
        for (int len = 3; len <= n; ++len) {
            for (int i = 0; i < n - len + 1; ++i) {
                int j = i + len - 1;
                dp[i][j] = max(min(dp[i + 1][j - 1], dp[i + 2][j]) + piles[i],
                               min(dp[i][j - 2], dp[i + 1][j - 1]) + piles[j]);
            }
        }
        
        return dp[0][n - 1] > sum - dp[0][n - 1];
    }
};

class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        return true;
    }
};
