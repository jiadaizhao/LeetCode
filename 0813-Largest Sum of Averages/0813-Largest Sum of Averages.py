class Solution:
    def largestSumOfAverages(self, A, K):
        """
        :type A: List[int]
        :type K: int
        :rtype: float
        """
        n = len(A)
        presum = [0] * (1 + n)
        for i in range(1, n + 1):
            presum[i] = presum[i - 1] + A[i - 1]
        
        dp = [presum[j] / j if j != 0 else 0 for j in range(1 + n)]
        result = dp[n]
        for k in range(2, K + 1):
            for j in range(n, 0, -1):
                for i in range(k - 1, j):
                    dp[j] = max(dp[j], dp[i] + (presum[j] - presum[i]) / (j - i))
            result = max(result, dp[n])
        return result

sol = Solution()
A = [1,2,3,4,5,6,7]
K = 4
result = sol.largestSumOfAverages(A, K)