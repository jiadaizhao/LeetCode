import collections
import copy
class Solution:
    def minDays(self, grid: List[List[int]]) -> int:
        m, n = len(grid), len(grid[0])
        def numOfIsland(grid):
            count = 0
            for i in range(m):
                for j in range(n):
                    if grid[i][j] == 1:
                        count += 1
                        Q = collections.deque([(i, j)])
                        while Q:
                            r, c = Q.popleft()
                            for nr, nc in (r-1, c), (r+1, c), (r, c-1), (r, c+1):
                                if 0 <= nr < m and 0 <= nc < n and grid[nr][nc] == 1:
                                    grid[nr][nc] = 0
                                    Q.append((nr, nc))
            return count
        
        if (numOfIsland(copy.deepcopy(grid)) != 1):
            return 0
        for i in range(m):
            for j in range(n):
                if grid[i][j] == 1:
                    gridCopy = copy.deepcopy(grid)
                    gridCopy[i][j] = 0
                    if numOfIsland(gridCopy) != 1:
                        return 1
        return 2
