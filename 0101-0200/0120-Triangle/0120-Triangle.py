class Solution:
    def minimumTotal(self, triangle: List[List[int]]) -> int:
        minSum = triangle[-1]
        for i in range(len(triangle) - 2, -1, -1):
            for j in range(i + 1):
                minSum[j] = min(minSum[j], minSum[j + 1]) + triangle[i][j]
        return minSum[0]
