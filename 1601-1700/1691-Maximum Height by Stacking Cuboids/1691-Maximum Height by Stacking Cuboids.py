class Solution:
    def maxHeight(self, cuboids: List[List[int]]) -> int:
        n = len(cuboids)
        cuboids = sorted(map(sorted, cuboids))
        dp = [0] * n
        for j in range(n):
            dp[j] = cuboids[j][2]
            for i in range(j):
                if all(cuboids[i][k] <= cuboids[j][k] for k in range(3)):
                    dp[j] = max(dp[j], dp[i] + cuboids[j][2])
        return max(dp)
