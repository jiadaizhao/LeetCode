class Solution:
    def largestIsland(self, grid: List[List[int]]) -> int:                
        m = len(grid)
        n = len(grid[0])
        parent = [i for i in range(m * n)]
        sz = [1] * (m*n)
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
                
        def area(i):
            return sz[find(i)]
                
        maxArea = 0
        for i in range(m):
            for j in range(n):
                if grid[i][j] == 1:
                    index = i * n + j
                    if i > 0 and grid[i - 1][j] == 1:
                        union(index, (i - 1)*n + j)                        
                    if j > 0 and grid[i][j - 1] == 1:
                        union(index, i*n + j - 1)
                    maxArea = max(maxArea, area(index))
                    
        for i in range(m):
            for j in range(n):
                if grid[i][j] == 0:
                    curr = 1
                    visited = set()
                    for r, c in (i-1, j), (i+1, j), (i, j-1), (i, j+1):
                        if 0 <= r < m and 0 <= c < n and grid[r][c] == 1:
                            p = find(r * n + c)
                            if p not in visited:
                                visited.add(p)
                                curr += sz[p]
                    
                    maxArea = max(maxArea, curr)
        return maxArea
