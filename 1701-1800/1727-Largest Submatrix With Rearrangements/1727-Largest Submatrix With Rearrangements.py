class Solution:
    def largestSubmatrix(self, matrix: List[List[int]]) -> int:
        m, n = len(matrix), len(matrix[0])
        height = [0] * n
        result = 0
        for i in range(m):
            for j in range(n):
                if matrix[i][j] == 1:
                    height[j] += 1
                else:
                    height[j] = 0
            
            h = sorted(height, reverse=True)
            for i in range(n):
                result = max(result, h[i] * (i + 1))
        
        return result
