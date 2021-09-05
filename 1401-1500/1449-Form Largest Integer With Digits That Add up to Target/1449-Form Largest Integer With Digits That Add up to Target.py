class Solution:
    def largestNumber(self, cost: List[int], target: int) -> str:
        dp = [0] + [-1] * target
        for t in range(1, target + 1):
            dp[t] = max((dp[t - c] * 10 + i + 1 if t >= c else -1) for i, c in enumerate(cost))
        return str(max(dp[target], 0))
