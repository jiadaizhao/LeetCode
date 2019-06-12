class Solution:
    def maxSumAfterPartitioning(self, A: List[int], K: int) -> int:
        dp = [0] * (1 + len(A))
        for j in range(1, 1 + len(A)):
            currMax = A[j - 1]
            for i in range(j, max(j - K, 0), -1):
                currMax = max(currMax, A[i - 1])
                dp[j] = max(dp[j], dp[i - 1] + currMax * (j - i + 1))

        return dp[-1]
