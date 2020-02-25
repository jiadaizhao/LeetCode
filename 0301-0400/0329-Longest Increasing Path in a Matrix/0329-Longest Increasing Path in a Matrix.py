class Solution:
    def longestIncreasingPath(self, matrix: List[List[int]]) -> int:
        if not matrix:
            return 0
        m, n = len(matrix), len(matrix[0])
        cache = [[0] * n for _ in range(m)]
        maxLen = 0
        def dfs(r, c):
            if cache[r][c] == 0:
                ml = 1
                for nr, nc in (r-1, c), (r+1, c), (r, c-1), (r, c+1):
                    if 0 <= nr < m and 0 <= nc < n and matrix[nr][nc] > matrix[r][c]:
                        ml = max(ml, 1 + dfs(nr, nc))                        
                cache[r][c] = ml
            return cache[r][c]
        
        for i in range(m):
            for j in range(n):
                maxLen = max(maxLen, dfs(i, j))
        return maxLen
