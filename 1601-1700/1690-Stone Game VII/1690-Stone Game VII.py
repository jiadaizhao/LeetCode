class Solution:
    def stoneGameVII(self, stones: List[int]) -> int:
        n = len(stones)
        presum = [0] * (n + 1)
        for i, s in enumerate(stones):
            presum[i + 1] = presum[i] + s
        dp = [[0] * n for _ in range(n)]
        for l in range(2, n + 1):
            for i in range(n - l + 1):
                j = i + l - 1
                dp[i][j] = max(presum[j + 1] - presum[i + 1] - dp[i + 1][j],
                               presum[j] - presum[i] - dp[i][j - 1])
        return dp[0][n - 1]
