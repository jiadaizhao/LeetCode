import collections
class Solution:
    def shortestDistance(self, grid: List[List[int]]) -> int:
        m, n = len(grid), len(grid[0])
        empty = 0
        distance = [[0] * n for _ in range(m)]
        for i in range(m):
            for j in range(n):
                if grid[i][j] == 1:
                    minDist = -1
                    Q = collections.deque([(i, j)])
                    dist = 0
                    while Q:
                        dist += 1
                        for _ in range(len(Q)):
                            r, c = Q.popleft()
                            for nr, nc in (r-1, c), (r+1, c), (r, c-1), (r, c+1):
                                if 0 <= nr < m and 0 <= nc < n and grid[nr][nc] == empty:
                                    Q.append((nr, nc))
                                    grid[nr][nc] -= 1
                                    distance[nr][nc] += dist
                                    if minDist == -1 or distance[nr][nc] < minDist:
                                        minDist = distance[nr][nc]
                    empty -= 1
        return minDist
