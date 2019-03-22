class Solution:
    def coinChange(self, coins: List[int], amount: int) -> int:
        dp = [1 + amount] * (1 + amount)
        dp[0] = 0
        for coin in coins:
            for a in range(coin, 1 + amount):
                dp[a] = min(dp[a], dp[a - coin] + 1)
        return dp[-1] if dp[-1] <= amount else -1
