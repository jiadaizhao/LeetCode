class Solution:
    def largestSumOfAverages(self, A: List[int], K: int) -> float:
        presum = [0] * (1 + len(A))
        for i in range(1, len(presum)):
            presum[i] = presum[i - 1] + A[i - 1]
            
        dp = [0] + [presum[j] / j for j in range(1, len(presum))]
        result = dp[-1]
        for k in range(2, K + 1):
            for j in range(len(A), 0, -1):
                for i in range(k - 1, j):
                    dp[j] = max(dp[j], dp[i] + (presum[j] - presum[i]) / (j - i))
            result = max(result, dp[-1])
        return result
