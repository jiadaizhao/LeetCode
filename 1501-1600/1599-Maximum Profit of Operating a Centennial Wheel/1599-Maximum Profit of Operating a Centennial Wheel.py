class Solution:
    def minOperationsMaxProfit(self, customers: List[int], boardingCost: int, runningCost: int) -> int:
        run = maxRun = 0
        profit = maxProfit = 0
        wait = 0
        i = 0
        while wait > 0 or i < len(customers):
            if i < len(customers):
                wait += customers[i]
                i += 1
            board = min(4, wait)
            wait -= board
            profit += board * boardingCost - runningCost
            run += 1
            if profit > maxProfit:
                maxProfit = profit
                maxRun = run
        return maxRun if maxProfit > 0 else -1
