class Solution:
    def maxKilledEnemies(self, grid: List[List[str]]) -> int:
        if not grid:
            return 0
        m, n = len(grid), len(grid[0])
        rowHits = maxCount = 0
        colHits = [0] * n
        for i in range(m):
            for j in range(n):
                if j == 0 or grid[i][j - 1] == 'W':
                    rowHits = 0
                    for k in range(j, n):
                        if grid[i][k] == 'E':
                            rowHits += 1
                        elif grid[i][k] == 'W':
                            break
                
                if i == 0 or grid[i - 1][j] == 'W':
                    colHits[j] = 0
                    for k in range(i, m):
                        if grid[k][j] == 'E':
                            colHits[j] += 1
                        elif grid[k][j] == 'W':
                            break
                            
                if grid[i][j] == '0':
                    maxCount = max(maxCount, rowHits + colHits[j])
        return maxCount
