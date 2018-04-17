class Solution {
public:
    double largestSumOfAverages(vector<int>& A, int K) {
        int n = A.size();
        vector<double> presum(1 + n);
        for (int i = 1; i <= n; ++i) {
            presum[i] = presum[i - 1] + A[i - 1];
        }
        
        vector<vector<double>> dp(1 + K, vector<double>(1 + n));
        
        for (int j = 1; j <= n; ++j) {
            dp[1][j] = presum[j] / j;
        }
        double result = dp[1][n];
        for (int k = 2; k <= K; ++k) {
            for (int j = 1; j <= n; ++j) {
                for (int i = k - 1; i < j; ++i) {
                    dp[k][j] = max(dp[k][j], dp[k - 1][i] + (presum[j] - presum[i]) / (j - i));
                }
            }
            result = max(result, dp[k][n]);
        }
        
        return result;
    }
};

// Optimize space to O(n)
class Solution {
public:
    double largestSumOfAverages(vector<int>& A, int K) {
        int n = A.size();
        vector<int> presum(1 + n);
        for (int i = 1; i <= n; ++i) {
            presum[i] = presum[i - 1] + A[i - 1];
        }
        
        vector<double> dp(1 + n);
        
        for (int j = 1; j <= n; ++j) {
            dp[j] = double(presum[j]) / j;
        }
        double result = dp[n];
        for (int k = 2; k <= K; ++k) {
            for (int j = n; j >= 1; --j) {
                for (int i = k - 1; i < j; ++i) {
                    dp[j] = max(dp[j], dp[i] + double(presum[j] - presum[i]) / (j - i));
                }
            }
            result = max(result, dp[n]);
        }
        
        return result;
    }
};
