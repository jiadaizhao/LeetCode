class Solution:
    def maxSideLength(self, mat: List[List[int]], threshold: int) -> int:
        m, n = len(mat), len(mat[0])
        presum = [[0] * (1 + n) for _ in range(1 + m)]
        maxLen = 0
        for i in range(1, 1 + m):
            for j in range(1, 1 + n):
                presum[i][j] = presum[i - 1][j] + presum[i][j - 1] - presum[i - 1][j - 1] + mat[i - 1][j - 1]
                if (i > maxLen and j > maxLen and 
                    presum[i][j] - presum[i - maxLen - 1][j] - presum[i][j - maxLen - 1] + presum[i - maxLen - 1][j - maxLen - 1] <= threshold):
                    maxLen += 1
        return maxLen
