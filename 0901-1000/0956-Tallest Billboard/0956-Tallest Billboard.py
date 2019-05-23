import collections
class Solution:
    def tallestBillboard(self, rods: List[int]) -> int:
        maxH = sum(rods) // 2
        dp = [[-1] * (maxH * 2 + 1) for _ in range(2)]
        dp[0][maxH] = 0
        for i in range(len(rods)):
            for j in range(len(dp[0])):
                if j - rods[i] >= 0 and dp[i&1][j - rods[i]] != -1:                    
                    dp[(i + 1) & 1][j] = max(dp[(i + 1) & 1][j], dp[i&1][j - rods[i]] + rods[i])
                if j + rods[i] < len(dp[0]) and dp[i&1][j + rods[i]] != -1:
                    dp[(i + 1) & 1][j] = max(dp[(i + 1) & 1][j], dp[i&1][j + rods[i]])

                dp[(i + 1) & 1][j] = max(dp[(i + 1) & 1][j], dp[i&1][j])
        return dp[len(rods) & 1][maxH]


class Solution2:
    def tallestBillboard(self, rods: List[int]) -> int:
        dp = {0:0}
        for rod in rods:
            curr = collections.defaultdict(int)
            for h in dp:
                curr[h + rod] = max(curr[h + rod], dp[h] + rod)
                curr[h] = max(curr[h], dp[h])
                curr[h - rod] = max(curr[h - rod], dp[h])
            dp = curr
        return dp[0]
