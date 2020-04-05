import math
class Solution:
    def isReflected(self, points: List[List[int]]) -> bool:
        minX = math.inf
        maxX = -math.inf
        table = set()
        for x, y in points:
            minX = min(minX, x)
            maxX = max(maxX, x)
            table.add((x, y))
        sum = minX + maxX
        for x, y in points:
            if (sum - x, y) not in table:
                return False
        return True
