class Solution:
    def stoneGameV(self, stoneValue: List[int]) -> int:
        n = len(stoneValue)
        dp = [[0] * n for _ in range(n)]
        mx = [[0] * n for _ in range(n)]
        for i in range(n):
            mx[i][i] = stoneValue[i]
        for j in range(1, n):
            mid = j
            s = stoneValue[j]
            rightHalf = 0
            for i in range(j - 1, -1, -1):
                s += stoneValue[i]
                while (rightHalf + stoneValue[mid]) * 2 <= s:
                    rightHalf += stoneValue[mid]
                    mid -= 1
                if rightHalf * 2 == s:
                    dp[i][j] = mx[i][mid]
                else:
                    dp[i][j] = (0 if mid == i else mx[i][mid - 1])
                if mid != j:
                    dp[i][j] = max(dp[i][j], mx[j][mid + 1])
                mx[i][j] = max(mx[i][j - 1], dp[i][j] + s)
                mx[j][i] = max(mx[j][i + 1], dp[i][j] + s)
        
        return dp[0][n - 1]
