class Solution:
    def findPaths(self, m: int, n: int, N: int, i: int, j: int) -> int:
        dp = [[0]*n for _ in range(m)]
        dp[i][j] = 1
        total = 0
        MOD = 1000000007
        for _ in range(N):
            temp = [[0]*n for _ in range(m)]
            for r in range(m):
                for c in range(n):
                    for nr, nc in (r-1, c), (r+1, c), (r, c-1), (r, c+1):
                        if 0 <= nr < m and 0 <= nc < n:
                            temp[nr][nc] = (temp[nr][nc] + dp[r][c]) % MOD
                        else:
                            total = (total + dp[r][c]) % MOD
            dp = temp
        return total
