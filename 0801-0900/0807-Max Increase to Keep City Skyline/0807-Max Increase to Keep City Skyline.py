class Solution:
    def maxIncreaseKeepingSkyline(self, grid: List[List[int]]) -> int:
        maxRows = [max(row) for row in grid]
        maxCols = [max(col) for col in zip(*grid)]
        return sum(min(maxRows[r], maxCols[c]) - val
                  for r, row in enumerate(grid)
                  for c, val in enumerate(row))
