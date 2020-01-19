class Solution:
    def matrixBlockSum(self, mat: List[List[int]], K: int) -> List[List[int]]:
        m, n = len(mat), len(mat[0])
        presum = [[0] * (1 + n) for _ in range(1 + m)]
        for i in range(1, 1 + m):
            for j in range(1, 1 + n):
                presum[i][j] = presum[i - 1][j] + presum[i][j - 1] - presum[i - 1][j - 1] + mat[i - 1][j - 1]
                
        result = [[0] * n for _ in range(m)]
        for i in range(m):
            for j in range(n):
                r1, c1 = max(0, i - K), max(0, j - K)
                r2, c2 = min(m - 1, i + K), min(n - 1, j + K)
                result[i][j] = presum[r2 + 1][c2 + 1] - presum[r2 + 1][c1] - presum[r1][c2 + 1] + presum[r1][c1]
        return result
