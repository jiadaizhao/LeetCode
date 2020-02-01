import math
class Solution:
    def minDifficulty(self, jobDifficulty: List[int], d: int) -> int:
        n = len(jobDifficulty)
        if n < d:
            return -1
        dp = [[0] + [math.inf] * n for _ in range(1 + d)]
        for k in range(1, d + 1):
            for j in range(k, n + 1):
                maxDiff = 0
                for i in range(j - 1, k - 2, -1):
                    maxDiff = max(maxDiff, jobDifficulty[i])
                    dp[k][j] = min(dp[k][j], dp[k - 1][i] + maxDiff)

        return dp[d][n] if dp[d][n] < math.inf else -1


# Optimize space
class Solution2:
    def minDifficulty(self, jobDifficulty: List[int], d: int) -> int:
        n = len(jobDifficulty)
        if n < d:
            return -1
        dp = [math.inf] * (1 + n)
        dp[0] = 0
        for k in range(1, d + 1):            
            for j in range(n, k - 1, -1):
                dp[j] = math.inf
                maxDiff = 0
                for i in range(j - 1, k - 2, -1):
                    maxDiff = max(maxDiff, jobDifficulty[i])
                    dp[j] = min(dp[j], dp[i] + maxDiff)
                    
        return dp[-1] if dp[-1] < math.inf else -1
