class Solution:
    def largestIsland(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: int
        """
        def findParent(parents, i):
            while parents[i] != i:
                parents[i] = parents[parents[i]]
                i = parents[i]
            return i
                
                
        m = len(grid)
        n = len(grid[0])
        parents = [i for i in range(m * n)]
        areas = [0] * (m * n)
        maxArea = 0
        for i in range(m):
            for j in range(n):
                if grid[i][j] == 1:
                    p1 = i * n + j
                    areas[p1] = 1
                    if i > 0 and grid[i - 1][j] == 1:
                        p1 = findParent(parents, (i - 1) * n + j)
                        parents[i * n + j] = p1
                        areas[p1] += 1
                        
                    if j > 0 and grid[i][j - 1] == 1:
                        p1 = findParent(parents, i * n + j - 1)
                        p2 = findParent(parents, i * n + j)
                        if p1 != p2:
                            parents[p2] = p1
                            areas[p1] += areas[p2]

                    maxArea = max(maxArea, areas[p1])
                    
        for i in range(m):
            for j in range(n):
                if grid[i][j] == 0:
                    areas[i * n + j] = 1
                    visited = set()
                    for r, c in [(i - 1, j), (i + 1, j), (i, j - 1), (i, j + 1)]:
                        if r >= 0 and r < m and c >= 0 and c < n and grid[r][c] == 1:
                            p = findParent(parents, r * n + c)
                            if p not in visited:
                                visited.add(p)
                                areas[i * n + j] += areas[p]
                    
                    maxArea = max(maxArea, areas[i * n + j])
        return maxArea
