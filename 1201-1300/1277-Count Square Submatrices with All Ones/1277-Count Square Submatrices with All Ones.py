class Solution:
    def countSquares(self, matrix: List[List[int]]) -> int:
        m, n = len(matrix), len(matrix[0])
        dp = [0] * (1 + n)
        total = 0
        for i in range(m):
            temp = [0] * (1 + n)
            for j in range(1, 1 + n):
                if matrix[i][j - 1] == 1:
                    temp[j] = 1 + min(dp[j - 1], dp[j], temp[j - 1])
                    total += temp[j]
            dp = temp
        return total
