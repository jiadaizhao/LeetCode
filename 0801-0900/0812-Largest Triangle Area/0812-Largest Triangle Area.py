class Solution:
    def largestTriangleArea(self, points: List[List[int]]) -> float:
        maxArea = 0
        
        def area(p1, p2, p3):
            return 0.5 * abs(p1[0] * p2[1] + p2[0] * p3[1] + p3[0] * p1[1] - p2[0] * p1[1] - p3[0] * p2[1] - p1[0] * p3[1])
        
        for i in range(len(points) - 2):
            for j in range(i + 1, len(points) - 1):
                for k in range(j + 1, len(points)):
                    maxArea = max(maxArea, area(points[i], points[j], points[k]))
        return maxArea
