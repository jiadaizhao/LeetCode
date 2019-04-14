class Solution:
    def maxProfit(self, prices: List[int], fee: int) -> int:
        sell = 0
        buy = -prices[0]
        for p in prices[1:]:
            buy = max(buy, sell - p)
            sell = max(sell, buy + p - fee)         
        return sell
