class Solution:
    def countNegatives(self, grid: List[List[int]]) -> int:
        m, n = len(grid), len(grid[0])
        row, col = m - 1, 0
        count = 0
        while row >= 0 and col < n:
            if grid[row][col] < 0:
                count += n - col
                row -= 1
            else:
                col += 1
        return count
