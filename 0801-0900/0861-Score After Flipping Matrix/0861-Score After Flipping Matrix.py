class Solution:
    def matrixScore(self, A: List[List[int]]) -> int:
        m, n = len(A), len(A[0])
        result = 0
        for j in range(n):
            row = sum(A[i][j] == A[i][0] for i in range(m))
            result += max(row, m - row) * (1 << (n - 1 - j))
        return result
