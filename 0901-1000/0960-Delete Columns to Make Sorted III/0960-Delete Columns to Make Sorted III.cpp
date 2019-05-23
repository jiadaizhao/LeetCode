class Solution {
public:
    int minDeletionSize(vector<string>& A) {
        int m = A[0].size(), N = A.size(), k;
        // Max Non-decreasing subsequence length
        vector<int> dp(m, 1);
        int minDel = m;
        for (int j = 0; j < m; ++j) {
            for (int i = 0; i < j; ++i) {
                for (k = 0; k < N; ++k) {
                    if (A[k][i] > A[k][j]) {
                        break;
                    }
                }
                if (k == N) {
                    dp[j] = max(dp[j], dp[i] + 1);
                }
            }
            
            minDel = min(minDel, m - dp[j]);
        }
        
        return minDel;
    }
};
