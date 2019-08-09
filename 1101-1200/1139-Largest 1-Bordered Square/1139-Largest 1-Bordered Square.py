class Solution:
    def largest1BorderedSquare(self, grid: List[List[int]]) -> int:
        m, n = len(grid), len(grid[0])
        left = [[0] * n for _ in range(m)]
        top = [[0] * n for _ in range(m)]
        for i in range(m):
            for j in range(n):
                if grid[i][j] == 1:
                    left[i][j] = left[i][j - 1] + 1 if j > 0 else 1
                    top[i][j] = top[i - 1][j] + 1 if i > 0 else 1
        maxLen = 0
        for i in range(m - 1, -1, -1):
            for j in range(n - 1, -1, -1):
                candidate = min(left[i][j], top[i][j])
                while candidate > maxLen:
                    if (left[i - candidate + 1][j] >= candidate and
                        top[i][j - candidate + 1] >= candidate):
                        maxLen = candidate
                        break
                    candidate -= 1

        return maxLen * maxLen
