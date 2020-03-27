import collections
class Solution:
    def hasValidPath(self, grid: List[List[int]]) -> bool:
        m, n = len(grid), len(grid[0])
        Q = collections.deque([(0, 0)])
        visited = [[False] * n for _ in range(m)]
        visited[0][0] = True
        direction = {1: [(0, -1), (0, 1)],
                     2: [(-1, 0), (1, 0)],
                     3: [(0, -1), (1, 0)],
                     4: [(0, 1), (1, 0)],
                     5: [(-1, 0), (0, -1)],
                     6: [(-1, 0), (0, 1)]}
        while Q:
            r, c = Q.popleft()
            if r == m - 1 and c == n - 1:
                return True
            for dr, dc in direction[grid[r][c]]:
                nr = r + dr
                nc = c + dc
                if 0 <= nr < m and 0 <= nc < n and not visited[nr][nc]:
                    for bdr, bdc in direction[grid[nr][nc]]:
                        if nr + bdr == r and nc + bdc == c:
                            Q.append((nr, nc))
                            visited[nr][nc] = True
                            break
        return False
