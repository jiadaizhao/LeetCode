class Solution:
    def profitableSchemes(self, G: int, P: int, group: List[int], profit: List[int]) -> int:
        dp = [[0]*(1 + G) for _ in range(1 + P)]
        dp[0][0] = 1
        MOD = 10**9 + 7
        for g0, p0 in zip(group, profit):
            for g in range(G, g0 - 1, -1):
                for p in range(P, -1, -1):
                    dp[p][g] = (dp[p][g] + dp[max(p - p0, 0)][g - g0]) % MOD

        return sum(dp[-1]) % MOD
