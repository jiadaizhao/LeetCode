# Definition for a point.
class Point:
    def __init__(self, a=0, b=0):
        self.x = a
        self.y = b

class Solution:
    def outerTrees(self, points: 'List[Point]') -> 'List[Point]':
        def orientation(p, q, r):
            return (q.x - p.x) * (r.y - q.y) - (q.y - p.y) * (r.x - q.x)
        
        points.sort(key=lambda p: (p.x, p.y))
        hull = []
        for point in points:
            while len(hull) >= 2 and orientation(hull[-2], hull[-1], point) < 0:
                hull.pop()
            hull.append(point)
        if len(hull) == len(points):
            return hull
        for point in points[:-1][::-1]:
            while len(hull) >= 2 and orientation(hull[-2], hull[-1], point) < 0:
                hull.pop()
            hull.append(point)
        hull.pop()
        return hull
