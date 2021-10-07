class Solution:
    def maxProductPath(self, grid: List[List[int]]) -> int:
        m, n = len(grid), len(grid[0])
        maxP = [[0] * n for _ in range(m)]
        minP = [[0] * n for _ in range(m)]
        maxP[0][0] = minP[0][0] = grid[0][0]
        for j in range(1, n):
            maxP[0][j] = maxP[0][j - 1] * grid[0][j]
            minP[0][j] = minP[0][j - 1] * grid[0][j]
            
        for i in range(1, m):
            maxP[i][0] = maxP[i - 1][0] * grid[i][0]
            minP[i][0] = minP[i - 1][0] * grid[i][0]
            for j in range(1, n):
                if grid[i][j] >= 0:
                    maxP[i][j] = max(maxP[i - 1][j], maxP[i][j - 1]) * grid[i][j]
                    minP[i][j] = min(minP[i - 1][j], minP[i][j - 1]) * grid[i][j]
                else:
                    maxP[i][j] = min(minP[i - 1][j], minP[i][j - 1]) * grid[i][j]
                    minP[i][j] = max(maxP[i - 1][j], maxP[i][j - 1]) * grid[i][j]
        return maxP[-1][-1] % (10 ** 9 + 7) if maxP[-1][-1] >= 0 else -1
