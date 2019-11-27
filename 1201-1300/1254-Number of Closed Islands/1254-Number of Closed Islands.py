class Solution:
    def closedIsland(self, grid: List[List[int]]) -> int:
        def dfs(r, c, val):
            grid[r][c] = val
            for nr, nc in (r-1, c), (r+1, c), (r, c-1), (r, c+1):
                if 0 <= nr < len(grid) and 0 <= nc < len(grid[0]) and grid[nr][nc] != val:
                    dfs(nr, nc, val)

        for i in range(len(grid)):
            for j in range(len(grid[i])):
                if grid[i][j] == 0 and (i == 0 or i == len(grid) - 1 or j == 0 or j == len(grid[i]) - 1):
                    dfs(i, j, 1)
                    
        count = 0
        for i in range(len(grid)):
            for j in range(len(grid[i])):
                if grid[i][j] == 0:
                    count += 1
                    dfs(i, j, 1)
        return count
