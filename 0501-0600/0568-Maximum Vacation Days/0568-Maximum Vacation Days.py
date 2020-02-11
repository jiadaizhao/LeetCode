class Solution:
    def maxVacationDays(self, flights: List[List[int]], days: List[List[int]]) -> int:
        N, K = len(flights), len(days[0])
        dp = [0] * N
        for i in range(K - 1, -1, -1):
            temp = [0] * N
            for j in range(N):
                temp[j] = dp[j] + days[j][i]
                for k in range(N):
                    if flights[j][k]:
                        temp[j] = max(temp[j], dp[k] + days[k][i])
            dp = temp
        return dp[0]
