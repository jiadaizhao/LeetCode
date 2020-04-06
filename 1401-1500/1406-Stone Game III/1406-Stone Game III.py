import math
class Solution:
    def stoneGameIII(self, stoneValue: List[int]) -> str:
        n = len(stoneValue)
        dp = [0] * (1 + n)
        for i in range(n - 1, -1, -1):
            dp[i] = -math.inf
            take = 0
            for j in range(i, min(i + 3, n)):
                take += stoneValue[j]
                dp[i] = max(dp[i], take - dp[j + 1])
        if dp[0] > 0:
            return 'Alice'
        elif dp[0] < 0:
            return 'Bob'
        else:
            return 'Tie'
