class Solution:
    def numMagicSquaresInside(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: int
        """
        def isMagic(grid, r, c):
            count = [0] * 10
            for i in range(3):
                for j in range(3):
                    if grid[r + i][c + j] < 1 or grid[r + i][c + j] > 9:
                        return False
                    count[grid[r + i][c + j]] += 1
                    if count[grid[r + i][c + j]] > 1:
                        return False
            return (grid[r][c] + grid[r][c + 1] + grid[r][c + 2] ==
                   grid[r + 1][c] + grid[r + 1][c + 1] + grid[r + 1][c + 2] ==
                   grid[r + 2][c] + grid[r + 2][c + 1] + grid[r + 2][c + 2] ==
                   grid[r][c] + grid[r + 1][c] + grid[r + 2][c] ==
                   grid[r][c + 1] + grid[r + 1][c + 1] + grid[r + 2][c + 1] ==
                   grid[r][c + 2] + grid[r + 1][c + 2] + grid[r + 2][c + 2] ==
                   grid[r][c] + grid[r + 1][c + 1] + grid[r + 2][c + 2] ==
                   grid[r][c + 2] + grid[r + 1][c + 1] + grid[r + 2][c] == 15)
        
        count = 0
        for i in range(len(grid) - 2):
            for j in range(len(grid[0]) - 2):
                if grid[i + 1][j + 1] == 5 and isMagic(grid, i, j):
                    count += 1
        return count
