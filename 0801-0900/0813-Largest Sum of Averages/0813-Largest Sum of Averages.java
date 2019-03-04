class Solution {
    public double largestSumOfAverages(int[] A, int K) {
        int n = A.length;
        int[] presum = new int[1 + n];
        for (int i = 1; i <= n; ++i) {
            presum[i] = presum[i - 1] + A[i - 1];
        }
        
        double[][] dp = new double[1 + K][1 + n];
        
        for (int j = 1; j <= n; ++j) {
            dp[1][j] = (double)(presum[j]) / j;
        }
        double result = dp[1][n];
        for (int k = 2; k <= K; ++k) {
            for (int j = 1; j <= n; ++j) {
                for (int i = k - 1; i < j; ++i) {
                    dp[k][j] = Math.max(dp[k][j], dp[k - 1][i] + (double)(presum[j] - presum[i]) / (j - i));
                }
            }
            result = Math.max(result, dp[k][n]);
        }
        
        return result;
    }
}
