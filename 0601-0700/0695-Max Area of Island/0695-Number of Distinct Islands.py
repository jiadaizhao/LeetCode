class Solution:
    def maxAreaOfIsland(self, grid: List[List[int]]) -> int:
        maxArea = 0
        m, n = len(grid), len(grid[0])
        def dfs(r, c):
            if grid[r][c] == 0:
                return 0
            total = 1
            grid[r][c] = 0
            for nr, nc in (r-1, c), (r+1, c), (r, c-1), (r, c+1):
                if 0 <= nr < m and 0 <= nc < n:
                    total += dfs(nr, nc)
            return total
        
        for i in range(m):
            for j in range(n):
                if grid[i][j] == 1:
                    maxArea = max(maxArea, dfs(i, j))
        return maxArea
