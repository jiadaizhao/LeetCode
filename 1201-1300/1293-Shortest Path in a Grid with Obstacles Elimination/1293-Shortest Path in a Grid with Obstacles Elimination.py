import collections
class Solution:
    def shortestPath(self, grid: List[List[int]], k: int) -> int:
        m, n = len(grid), len(grid[0])
        if k >= m - 1 + n - 1:
            return m + n - 2
        Q = collections.deque([(0, 0, k)])
        visited = set([(0, 0, k)])
        step = 0
        while Q:
            for _ in range(len(Q)):
                r, c, e = Q.popleft()
                if r == m - 1 and c == n - 1:
                    return step
                for nr, nc in (r-1, c), (r+1, c), (r, c-1), (r, c+1):
                    if 0 <= nr < m and 0 <= nc < n:
                        if grid[nr][nc] == 0 and (nr, nc, e) not in visited:
                            Q.append((nr, nc, e))
                            visited.add((nr, nc, e))
                        elif grid[nr][nc] == 1 and e > 0 and (nr, nc, e - 1) not in visited:
                            Q.append((nr, nc, e - 1))
                            visited.add((nr, nc, e - 1))                
            step += 1
            
        return -1
