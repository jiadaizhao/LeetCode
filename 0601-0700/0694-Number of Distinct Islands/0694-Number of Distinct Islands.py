# DFS
class Solution:
    def numDistinctIslands(self, grid: List[List[int]]) -> int:
        if not grid:
            return 0
        m, n = len(grid), len(grid[0])
        table = set()
        def dfs(r, c, di):
            if 0 <= r < m and 0 <= c < n and grid[r][c] == 1:
                grid[r][c] = 0
                path.append(di)
                dfs(r - 1, c, 1)
                dfs(r + 1, c, 2)
                dfs(r, c - 1, 3)
                dfs(r, c + 1, 4)
                path.append(0)
                
        for i in range(m):
            for j in range(n):
                if grid[i][j] == 1:
                    path = []
                    dfs(i, j, 0)
                    table.add(tuple(path))
        return len(table)

# BFS
import collections
class Solution2:
    def numDistinctIslands(self, grid: List[List[int]]) -> int:
        if not grid:
            return 0
        m, n = len(grid), len(grid[0])
        table = set()
        dr = [-1, 1, 0, 0]
        dc = [0, 0, -1, 1]
        for i in range(m):
            for j in range(n):
                if grid[i][j] == 1:                    
                    Q = collections.deque([(i, j)])
                    grid[i][j] = 0
                    path = []
                    while Q:
                        r, c = Q.popleft()
                        for k in range(4):
                            nr = r + dr[k]
                            nc = c + dc[k]
                            if 0 <= nr < m and 0 <= nc < n and grid[nr][nc] == 1:
                                Q.append((nr, nc))
                                grid[nr][nc] = 0
                                path.append(k + 1)
                        path.append(0)
                    table.add(tuple(path))
        return len(table)
