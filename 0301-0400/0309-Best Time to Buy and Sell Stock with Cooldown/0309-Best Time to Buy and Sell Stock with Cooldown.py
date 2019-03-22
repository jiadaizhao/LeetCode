class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        if not prices:
            return 0
        
        buy = [0] * (1 + len(prices))
        sell = [0] * (1 + len(prices))
        buy[1] = -prices[0]
        for i in range(2, 1 + len(prices)):
            sell[i] = max(sell[i - 1], buy[i - 1] + prices[i - 1])
            buy[i] = max(buy[i - 1], sell[i - 2] - prices[i - 1])
        return sell[-1]

class Solution2:
    def maxProfit(self, prices: List[int]) -> int:
        if not prices:
            return 0
        
        buy = -prices[0]
        sell1 = sell2 = 0
        for i in range(2, 1 + len(prices)):
            temp = sell2
            sell2 = max(sell2, buy + prices[i - 1])
            buy = max(buy, sell1 - prices[i - 1])
            sell1 = temp
        return sell2
