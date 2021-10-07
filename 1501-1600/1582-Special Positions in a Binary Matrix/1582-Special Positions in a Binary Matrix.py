class Solution:
    def numSpecial(self, mat: List[List[int]]) -> int:
        m, n = len(mat), len(mat[0])
        rows = [0] * m
        cols = [0] * n
        for i in range(m):
            for j in range(n):
                if mat[i][j] == 1:
                    rows[i] += 1
                    cols[j] += 1
        result = 0
        for i in range(m):
            for j in range(n):
                if mat[i][j] == 1 and rows[i] == 1 and cols[j] == 1:
                    result += 1
        return result
