class Solution:
    def getMaximumGold(self, grid: List[List[int]]) -> int:
        m = len(grid)
        n = len(grid[0])
        maxGold = 0
        def dfs(row, col):
            orig = grid[row][col]
            gold = orig
            grid[row][col] = 0
            
            for nr, nc in (row - 1, col), (row + 1, col), (row, col - 1), (row, col + 1):
                if 0 <= nr < m and 0 <= nc < n and grid[nr][nc] > 0:
                    gold = max(gold, orig + dfs(nr, nc))

            grid[row][col] = orig
            return gold

        for i in range(m):
            for j in range(n):
                if grid[i][j] > 0:
                    maxGold = max(maxGold, dfs(i, j))
        
        return maxGold
