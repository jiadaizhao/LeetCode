class Solution {
public:
    int numOfArrays(int n, int m, int k) {
        int MOD = 1e9 + 7;
        long presum[n + 1][m + 1][k + 1];
        memset(presum, 0, sizeof(presum));
        for (int i = 1; i <= m; ++i) {
            presum[1][i][1] = i;
        }
        
        for (int a = 2; a <= n; ++a) {
            for (int b = 1; b <= m; ++b) {
                for (int c = 1; c <= k; ++c) {
                    long curr = b * (presum[a - 1][b][c] - presum[a - 1][b - 1][c] + MOD) % MOD;
                    curr = (curr + presum[a - 1][b - 1][c - 1]) % MOD;
                    presum[a][b][c] = (presum[a][b - 1][c] + curr) % MOD;
                }
            }
        }
        
        return presum[n][m][k];
    }
};
