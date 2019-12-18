class Solution:
    def probabilityOfHeads(self, prob: List[float], target: int) -> float:
        dp = [[0] * (1 + target) for _ in range(1 + len(prob))]
        dp[0][0] = 1
        for i in range(1, 1 + len(prob)):
            dp[i][0] = dp[i - 1][0] * (1 - prob[i - 1])
            for j in range(1, 1 + min(target, i)):
                dp[i][j] = dp[i - 1][j - 1] * prob[i - 1] + dp[i - 1][j] * (1 - prob[i - 1])

        return dp[-1][-1]


# Optimize space
class Solution:
    def probabilityOfHeads(self, prob: List[float], target: int) -> float:
        dp = [0] * (1 + target)
        dp[0] = 1
        for i in range(1, 1 + len(prob)):
            for j in range(min(target, i), -1, -1):
                dp[j] = (dp[j - 1] if j > 0 else 0) * prob[i - 1] + dp[j] * (1 - prob[i - 1])
        return dp[-1]
