class Solution {
public:
    bool splitArraySameAverage(vector<int>& A) {
        int sum = 0, n = A.size();
        for (int a : A) {
            sum += a;
        }
        vector<vector<bool>> dp(1 + n, vector<bool>(sum));
        dp[0][0] = true;
        for (int i = 1; i <= n; ++i) {
            for (int j = i - 1; j > 0; --j) {
                for (int k = sum - 1; k >= A[i - 1]; --k) {
                    if (dp[j - 1][k - A[i - 1]]) {
                        dp[j][k] = true;
                    }
                }                
            }
        }
        
        for (int i = 1; i < n; ++i) {
            for (int j = 1; j < sum; ++j) {
                if (dp[i][j] && j * (n - i) == i * (sum - j)) {
                    return true;
                }
            }
        }
        return false;
    }
};
