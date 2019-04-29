class Solution:
    def hitBricks(self, grid: List[List[int]], hits: List[List[int]]) -> List[int]:
        m = len(grid)
        n = len(grid[0])
        gc = [grid[i][:] for i in range(m)]
        parent = [i for i in range(1 + m*n)]
        sz = [1] * (1 + m*n)
        for row, col in hits:
            gc[row][col] = 0   
        
        def find(i):
            while i != parent[i]:
                parent[i] = parent[parent[i]]
                i = parent[i]
            return i
        
        def union(p, q):
            rootP = find(p)
            rootQ = find(q)
            if rootP == rootQ:
                return
            if sz[rootP] < sz[rootQ]:
                parent[rootP] = rootQ
                sz[rootQ] += sz[rootP]
            else:
                parent[rootQ] = rootP
                sz[rootP] += sz[rootQ]
                
        def conTopNum():
            return sz[find(m*n)] - 1
            
        for i in range(m):
            for j in range(n):
                if gc[i][j] == 1:
                    index = i*n + j
                    if i == 0:
                        union(index, m*n)
                    if i > 0 and gc[i - 1][j] == 1:
                        union(index, (i - 1)*n + j)
                    if j > 0 and gc[i][j - 1] == 1:
                        union(index, i*n + j - 1)
        
        result = [0] * len(hits)
        for i in range(len(hits) - 1, -1, -1):
            r, c = hits[i]
            if grid[r][c] == 1:
                prevTop = conTopNum()
                index = r*n + c
                if r == 0:
                    union(index, m*n)
                for nr, nc in (r-1, c), (r+1, c), (r, c-1), (r, c+1):
                    if 0 <= nr < m and 0 <= nc < n and gc[nr][nc] == 1:
                        union(index, nr*n + nc)
                gc[r][c] = 1
                result[i] = max(0, conTopNum() - prevTop - 1)
                
        return result
