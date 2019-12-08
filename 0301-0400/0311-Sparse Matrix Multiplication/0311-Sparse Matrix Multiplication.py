class Solution:
    def multiply(self, A: List[List[int]], B: List[List[int]]) -> List[List[int]]:
        m, n, p = len(A), len(A[0]), len(B[0])
        result = [[0] * p for _ in range(m)]
        for i in range(m):
            for j in range(n):
                if A[i][j]:
                    for k in range(p):
                        result[i][k] += A[i][j] * B[j][k]
        return result
