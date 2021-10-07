import math
class Solution:
    def visiblePoints(self, points: List[List[int]], angle: int, location: List[int]) -> int:
        posx, posy = location
        pos = []
        same = 0
        for x, y in points:
            if x == posx and y == posy:
                same += 1
            else:
                pos.append(math.atan2(y - posy, x - posx))
        pos.sort()
        pos = pos + [p + 2 * math.pi for p in pos]
        maxNum = start = 0
        ang = angle * math.pi / 180
        for i, p in enumerate(pos):
            while p - pos[start] > ang:
                start += 1
            maxNum = max(maxNum, i - start + 1)
        return maxNum + same
