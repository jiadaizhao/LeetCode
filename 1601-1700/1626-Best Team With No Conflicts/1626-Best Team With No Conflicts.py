class Solution:
    def bestTeamScore(self, scores: List[int], ages: List[int]) -> int:
        n = len(scores)
        p = sorted(zip(ages, scores))
        dp = [0] * n
        for j in range(n):
            dp[j] = p[j][1]
            for i in range(j):
                if p[j][0] == p[i][0] or p[j][1] >= p[i][1]:
                    dp[j] = max(dp[j], dp[i] + p[j][1])
        return max(dp)
