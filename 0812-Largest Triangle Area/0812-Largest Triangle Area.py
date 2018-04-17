class Solution:
    def largestTriangleArea(self, points):
        """
        :type points: List[List[int]]
        :rtype: float
        """
        maxArea = 0
        n = len(points)
        
        def area(p1, p2, p3):
            return 0.5 * abs(p1[0] * p2[1] + p2[0] * p3[1] + p3[0] * p1[1] - p2[0] * p1[1] - p3[0] * p2[1] - p1[0] * p3[1])
        
        for i in range(n - 2):
            for j in range(i + 1, n - 1):
                for k in range(j + 1, n):
                    maxArea = max(maxArea, area(points[i], points[j], points[k]))
        return maxArea
