import math
class Solution:
    def findMinArrowShots(self, points: 'List[List[int]]') -> 'int':
        points.sort()
        count = 0
        prev = -math.inf
        for point in points:
            if point[0] > prev:
                count += 1
                prev = point[1]
            else:
                prev = min(prev, point[1])
        return count
