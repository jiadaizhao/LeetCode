class Solution:
    def minCostClimbingStairs(self, cost: List[int]) -> int:
        dp0 = cost[0]
        dp1 = cost[1]
        for i in range(2, len(cost)):
            dp2 = min(dp0, dp1) + cost[i]
            dp0 = dp1
            dp1 = dp2
        return min(dp0, dp1)
