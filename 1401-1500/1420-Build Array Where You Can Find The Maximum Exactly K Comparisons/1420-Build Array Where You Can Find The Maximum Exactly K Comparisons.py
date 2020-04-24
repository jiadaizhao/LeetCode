class Solution:
    def numOfArrays(self, n: int, m: int, k: int) -> int:
        MOD = 10 ** 9 + 7
        presum = [[[0] * (k + 1) for _ in range(m + 1)] for _ in range(n + 1)]
        for i in range(1, m + 1):
            presum[1][i][1] = i
            
        for a in range(2, n + 1):
            for b in range(1, m + 1):
                for c in range(1, k + 1):
                    curr = b * (presum[a - 1][b][c] - presum[a - 1][b - 1][c]) % MOD
                    curr = (curr + presum[a - 1][b - 1][c - 1]) % MOD
                    presum[a][b][c] = (presum[a][b - 1][c] + curr) % MOD
        
        return presum[n][m][k]
