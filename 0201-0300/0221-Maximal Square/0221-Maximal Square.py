class Solution:
    def maximalSquare(self, matrix: List[List[str]]) -> int:
        if not matrix:
            return 0
        m, n = len(matrix), len(matrix[0])
        dp = [[0] * (1 + n) for _ in range(1 + m)]
        maxArea = 0
        for i in range(1, 1 + m):
            for j in range(1, 1 + n):
                if matrix[i - 1][j - 1] == '1':
                    dp[i][j] = 1 + min(dp[i - 1][j], dp[i - 1][j - 1], dp[i][j - 1])
                    maxArea = max(maxArea, dp[i][j] ** 2)
        return maxArea


class Solution2:
    def maximalSquare(self, matrix: List[List[str]]) -> int:
        if not matrix:
            return 0
        m, n = len(matrix), len(matrix[0])
        dp = [0] * (1 + n)
        maxArea = 0
        for i in range(1, 1 + m):
            temp = [0] * (1 + n)
            for j in range(1, 1 + n):                
                if matrix[i - 1][j - 1] == '1':
                    temp[j] = 1 + min(dp[j], temp[j - 1], dp[j - 1])
                    maxArea = max(maxArea, temp[j] ** 2)
            dp = temp

        return maxArea


class Solution3:
    def maximalSquare(self, matrix: List[List[str]]) -> int:
        if not matrix:
            return 0
        m, n = len(matrix), len(matrix[0])
        dp = [0] * (1 + n)
        maxArea = 0
        for i in range(1, 1 + m):
            temp1 = dp[0]
            for j in range(1, 1 + n):
                temp2 = dp[j]
                if matrix[i - 1][j - 1] == '1':
                    dp[j] = 1 + min(dp[j], dp[j - 1], temp1)
                    maxArea = max(maxArea, dp[j] ** 2)
                else:
                    dp[j] = 0
                temp1 = temp2

        return maxArea
