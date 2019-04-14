class Solution:
    def knightProbability(self, N: int, K: int, r: int, c: int) -> float:
        dp = [[0]*N for _ in range(N)]
        dp[r][c] = 1
        for _ in range(K):
            temp = [[0]*N for _ in range(N)]
            for i in range(N):
                for j in range(N):
                    for nr, nc in (i-2, j-1), (i-2, j+1), (i-1, j-2), (i-1, j+2), (i+1, j-2), (i+1, j+2), (i+2, j-1), (i+2, j+1):
                        if 0 <= nr < N and 0 <= nc < N:
                            temp[i][j] += dp[nr][nc] / 8
            dp = temp
        return sum(map(sum, dp))
