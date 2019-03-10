class Solution:
    def numTrees(self, n: int) -> int:
        dp = [0] * (n + 1)
        dp[0] = 1
        for j in range(1, n + 1):
            for i in range(j):
                dp[j] += dp[i] * dp[j - i - 1]
        return dp[n]
