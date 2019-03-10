class Solution:
    def maximalRectangle(self, matrix: List[List[str]]) -> int:
        m = len(matrix)
        if m == 0:
            return 0
        n = len(matrix[0])
        if n == 0:
            return 0
        heights = [0] * (n + 1)
        maxArea = 0
        for i in range(m):
            St = []
            for j in range(n + 1):
                if j < n and matrix[i][j] == '1':
                    heights[j] += 1
                else:
                    heights[j] = 0
                while St and heights[St[-1]] >= heights[j]:
                    h = heights[St.pop()]
                    w = j - 1 - St[-1] if St else j
                    maxArea = max(maxArea, w*h)
                St.append(j)
        return maxArea
