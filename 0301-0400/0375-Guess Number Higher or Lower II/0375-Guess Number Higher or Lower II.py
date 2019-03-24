import math
class Solution:
    def getMoneyAmount(self, n: int) -> int:
        dp = [[0]*(2 + n) for _ in range(2 + n)]
        for l in range(2, 1 + n):
            for i in range(n - l + 2):
                j = i + l - 1
                dp[i][j] = math.inf
                for k in range(i, j + 1):
                    dp[i][j] = min(dp[i][j], k + max(dp[i][k - 1], dp[k + 1][j]))

        return dp[1][n]
