import math
class Solution:
    def minCost(self, n: int, cuts: List[int]) -> int:
        cuts.extend([0, n])
        cuts.sort()
        m = len(cuts)
        dp = [[0] * m for _ in range(m)]
        
        for l in range(3, m + 1):
            for i in range(m - l + 1):
                j = i + l - 1
                dp[i][j] = math.inf
                for k in range(i + 1, j):
                    dp[i][j] = min(dp[i][j], cuts[j] - cuts[i] + dp[i][k] + dp[k][j])

        return dp[0][m - 1]
