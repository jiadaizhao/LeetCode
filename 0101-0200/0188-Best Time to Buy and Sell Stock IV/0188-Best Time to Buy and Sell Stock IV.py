class Solution:
    def maxProfit(self, k: int, prices: List[int]) -> int:
        if k >= len(prices) // 2:
            profit = 0
            for i in range(1, len(prices)):
                diff = prices[i] - prices[i - 1]
                if diff > 0:
                    profit += diff
            return profit
        
        dp = [0] * len(prices)
        for i in range(1, k + 1):
            localMax = dp[0] - prices[0]
            for j in range(1, len(prices)):
                temp = localMax
                localMax = max(localMax, dp[j] - prices[j])
                dp[j] = max(dp[j - 1], prices[j] + temp)
        return dp[-1]
