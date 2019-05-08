class Solution:
    def surfaceArea(self, grid: List[List[int]]) -> int:
        total = 0
        for i in range(len(grid)):
            for j in range(len(grid[i])):
                if grid[i][j] > 0:
                    total += grid[i][j] * 4 + 2
                    if i > 0:
                        total -= min(grid[i][j], grid[i - 1][j]) * 2
                    if j > 0:
                        total -= min(grid[i][j], grid[i][j - 1]) * 2
        return total
