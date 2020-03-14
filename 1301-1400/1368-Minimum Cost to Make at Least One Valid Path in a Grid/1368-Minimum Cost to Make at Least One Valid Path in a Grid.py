class Solution:
    def minCost(self, grid: List[List[int]]) -> int:
        m, n = len(grid), len(grid[0])
        Q = collections.deque()        
        visited = [[False] * n for _ in range(m)]
        def addQ(r, c):
            while 0 <= r < m and 0 <= c < n and not visited[r][c]:
                Q.append((r, c))
                visited[r][c] = True
                if grid[r][c] == 1:
                    c += 1
                elif grid[r][c] == 2:
                    c -= 1
                elif grid[r][c] == 3:
                    r += 1
                else:
                    r -= 1
        addQ(0, 0)
        step = 0
        while Q:
            for _ in range(len(Q)):
                r, c = Q.popleft()
                if r == m - 1 and c == n - 1:
                    return step
                for nr, nc in (r-1, c), (r+1, c), (r, c-1), (r, c+1):
                    if 0 <= nr < m and 0 <= nc < n and not visited[nr][nc]:
                        addQ(nr, nc)
            step += 1
        
        return -1
