import bisect
class Solution:
    def jobScheduling(self, startTime: List[int], endTime: List[int], profit: List[int]) -> int:
        jobs = sorted(zip(startTime, endTime, profit), key=lambda x : x[1])
        # [endTime, maxProfit]
        dp = [[0, 0]]
        for s, e, p in jobs:
            index = bisect.bisect_left(dp, [s + 1]) - 1
            currMaxProfit = p + dp[index][1]
            if currMaxProfit > dp[-1][1]:
                dp.append([e, currMaxProfit])

        return dp[-1][1]
