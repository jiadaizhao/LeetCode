from functools import lru_cache
class Solution:
    def ways(self, pizza: List[str], k: int) -> int:
        MOD = 10 ** 9 + 7
        m, n = len(pizza), len(pizza[0])
        presum = [[0] * (1 + n) for _ in range(1 + m)]
        for r in range(m - 1, -1, -1):
            for c in range(n - 1, -1, -1):
                presum[r][c] = presum[r][c + 1] + presum[r + 1][c] - presum[r + 1][c + 1] + (1 if pizza[r][c] == 'A' else 0)
               
        @lru_cache(None)
        def dfs(row, col, k):
            if presum[row][col] == 0:
                return 0
            if k == 0:
                return 1
            result = 0
            for r in range(row + 1, m):
                if presum[row][col] - presum[r][col] > 0:
                    result = (result + dfs(r, col, k - 1)) % MOD
            for c in range(col + 1, n):
                if presum[row][col] - presum[row][c] > 0:
                    result = (result + dfs(row, c, k - 1)) % MOD
            return result
        
        return dfs(0, 0, k - 1)
