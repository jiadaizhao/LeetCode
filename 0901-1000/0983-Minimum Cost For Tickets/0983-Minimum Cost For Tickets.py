class Solution:
    def mincostTickets(self, days: List[int], costs: List[int]) -> int:
        dp = [0] * (days[-1] + 1)
        table = set(days)
        for i in range(1, len(dp)):
            if i in table:
                dp[i] = min(dp[i - 1] + costs[0], dp[max(0, i - 7)] + costs[1], dp[max(0, i - 30)] + costs[2])
            else:
                dp[i] = dp[i - 1]

        return dp[-1]
