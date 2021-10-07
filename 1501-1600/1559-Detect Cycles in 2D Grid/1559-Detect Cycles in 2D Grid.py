class Solution:
    def containsCycle(self, grid: List[List[str]]) -> bool:
        m, n = len(grid), len(grid[0])
        visited = [[False] * n for _ in range(m)]
        def dfs(r, c, pr, pc):
            visited[r][c] = True
            for nr, nc in (r-1, c), (r+1, c), (r, c-1), (r, c+1):
                if 0 <= nr < m and 0 <= nc < n and (nr != pr or nc != pc) and grid[nr][nc] == grid[r][c]:
                    if visited[nr][nc]:
                        return True
                    if dfs(nr, nc, r, c):
                        return True
            return False
        for r in range(m):
            for c in range(n):
                if not visited[r][c] and dfs(r, c, -1, -1):
                    return True
        return False
