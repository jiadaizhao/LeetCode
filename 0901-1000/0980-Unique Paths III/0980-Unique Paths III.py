class Solution:
    def uniquePathsIII(self, grid: List[List[int]]) -> int:
        empty = 1
        for i in range(len(grid)):
            for j in range(len(grid[i])):
                if grid[i][j] == 1:
                    sr = i
                    sc = j
                elif grid[i][j] == 0:
                    empty += 1
        
        total = 0
        def dfs(row, col):
            nonlocal empty, total
            if grid[row][col] == 2:
                if empty == 0:
                    total += 1
                return
          
            grid[row][col] = -1
            empty -= 1
            for nr, nc in (row-1, col), (row+1, col), (row, col-1), (row, col+1):
                if 0 <= nr < len(grid) and 0 <= nc < len(grid[0]) and grid[nr][nc] != -1:
                    dfs(nr, nc)
            empty += 1
            grid[row][col] = 0

        dfs(sr, sc)
        return total          
