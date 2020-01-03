import collections
class Solution:
    def numDistinctIslands2(self, grid: List[List[int]]) -> int:
        if not grid:
            return 0
        m, n = len(grid), len(grid[0])
        table = set()
        dr = [-1, 1, 0, 0]
        dc = [0, 0, -1, 1]
        def norm(path):
            s = [[] for _ in range(8)]
            for r, c in path:
                s[0].append((r, c))
                s[1].append((r, -c))
                s[2].append((-r, c))
                s[3].append((-r, -c))
                s[4].append((c, r))
                s[5].append((c, -r))
                s[6].append((-c, r))
                s[7].append((-c, -r))
        
            for v in s:
                v.sort()
                
            for v in s:
                for i in range(1, len(v)):
                    v[i] = (v[i][0] - v[0][0], v[i][1] - v[0][1])
                v[0] = (0, 0)
            return sorted(s)[0]    
            
            
        for i in range(m):
            for j in range(n):
                if grid[i][j] == 1:                    
                    Q = collections.deque([(i, j)])
                    grid[i][j] = 0
                    path = []
                    while Q:
                        r, c = Q.popleft()
                        path.append((r, c))
                        for k in range(4):
                            nr = r + dr[k]
                            nc = c + dc[k]
                            if 0 <= nr < m and 0 <= nc < n and grid[nr][nc] == 1:
                                Q.append((nr, nc))
                                grid[nr][nc] = 0
                    table.add(tuple(norm(path)))
        return len(table)
