# Definition for a point.
# class Point:
#     def __init__(self, a=0, b=0):
#         self.x = a
#         self.y = b

import collections
class Solution:
    def maxPoints(self, points: List[Point]) -> int:
        maxNum = 0
        
        def gcd(a, b):
            while b:
                a, b = b, a%b
            return a

        for i in range(len(points)):
            same = 0
            vertical = 0
            table = collections.Counter()
            localMax = 0
            for j in range(i):
                if points[i].x == points[j].x and points[i].y == points[j].y:
                    same += 1
                elif points[i].x == points[j].x:
                    vertical += 1
                else:
                    dx = points[j].x - points[i].x
                    dy = points[j].y - points[i].y
                    gc = gcd(dx, dy)
                    dx //= gc
                    dy //= gc
                    table[(dx, dy)] += 1
                    localMax = max(localMax, table[(dx, dy)])
            maxNum = max(maxNum, max(vertical, localMax) + same + 1)
        return maxNum
