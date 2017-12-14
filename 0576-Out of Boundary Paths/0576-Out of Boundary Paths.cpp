class Solution {
public:
    int findPaths(int m, int n, int N, int i, int j) {
        if (N == 0) {
            return 0;
        }
        
        vector<vector<int>> dp(m, vector<int>(n));
        dp[i][j] = 1;
        int MOD = 1000000007;
        
        vector<int> dr = {-1, 1, 0, 0};
        vector<int> dc = {0, 0, -1, 1};
        int sum = 0;
        for (int k = 0; k < N; ++k) {
            vector<vector<int>> temp(m, vector<int>(n));
            for (int r = 0; r < m; ++r) {
                for (int c = 0; c < n; ++c) {
                    if (r == m - 1) {
                        sum = (sum + dp[r][c]) % MOD;
                    }
                    
                    if (r == 0) {
                        sum = (sum + dp[r][c]) % MOD;
                    }
                    
                    if (c == n - 1) {
                        sum = (sum + dp[r][c]) % MOD;
                    }
                    
                    if (c == 0) {
                        sum = (sum + dp[r][c]) % MOD;
                    }
                    
                    for (int l = 0; l < dr.size(); ++l) {
                        int nr = r + dr[l];
                        int nc = c + dc[l];
                        if (nr >= 0 && nr < m && nc >= 0 && nc < n) {
                            temp[r][c] = (temp[r][c] + dp[nr][nc]) % MOD;
                        }
                    }
                }
            }
            dp = temp;
        }
        
        return sum;
    }
};
