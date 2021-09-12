from functools import lru_cache
class Solution:
    def cherryPickup(self, grid: List[List[int]]) -> int:
        m, n = len(grid), len(grid[0])
        @lru_cache(None)
        def dfs(r, c1, c2):
            if r == m:
                return 0
            total = 0
            for dc1 in range(-1, 2):
                for dc2 in range(-1, 2):
                    nc1 = c1 + dc1
                    nc2 = c2 + dc2
                    if 0 <= nc1 < n and 0 <= nc2 < n:
                        total = max(total, dfs(r + 1, nc1, nc2))
            return total + (grid[r][c1] + grid[r][c2] if c1 != c2 else grid[r][c1])
        
        return dfs(0, 0, n - 1)
