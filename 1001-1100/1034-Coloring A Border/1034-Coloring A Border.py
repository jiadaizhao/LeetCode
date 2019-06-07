class Solution:
    def colorBorder(self, grid: List[List[int]], r0: int, c0: int, color: int) -> List[List[int]]:
        def dfs(r, c, color):
            grid[r][c] = -color
            for nr, nc in (r-1, c), (r+1, c), (r, c-1), (r, c+1):
                if 0 <= nr < len(grid) and 0 <= nc < len(grid[0]) and grid[nr][nc] == color:
                    dfs(nr, nc, color)
            if 0 < r < len(grid) - 1 and 0 < c < len(grid[0]) - 1 and \
            abs(grid[r - 1][c]) == abs(grid[r + 1][c]) == abs(grid[r][c - 1]) == abs(grid[r][c + 1]) == color:
                grid[r][c] = color
                
        dfs(r0, c0, grid[r0][c0])
        for r in range(len(grid)):
            for c in range(len(grid[0])):
                if grid[r][c] < 0:
                    grid[r][c] = color
        return grid
