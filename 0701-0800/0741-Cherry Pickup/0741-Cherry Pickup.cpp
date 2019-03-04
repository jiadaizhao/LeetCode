class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int N = grid.size();
        vector<vector<int>> dp(N, vector<int>(N));
        dp[0][0] = grid[0][0];
        int maxStep = 2 * N - 2;
        for (int k = 1; k <= maxStep; ++k) {
            for (int i = N - 1; i >= 0; --i) {
                for (int p = N - 1; p >= 0; --p) {
                    int j = k - i;
                    int q = k - p;
                    if (j < 0 || j >= N || q < 0 || q >= N || grid[i][j] == -1 || grid[p][q] == -1) {
                        dp[i][p] = -1;
                        continue;
                    }
                    
                    if (i > 0) {
                        dp[i][p] = max(dp[i][p], dp[i - 1][p]);
                    }
                    if (p > 0) {
                        dp[i][p] = max(dp[i][p], dp[i][p - 1]);
                    }
                    if (i > 0 && p > 0) {
                        dp[i][p] = max(dp[i][p], dp[i - 1][p - 1]);
                    }
                    if (dp[i][p] >= 0) {
                        dp[i][p] += grid[i][j] + ((i != p) ? grid[p][q] : 0);
                    }                    
                }
            }
        }
        
        return dp[N - 1][N - 1] > 0 ? dp[N - 1][N - 1] : 0;
    }
};
