import collections
import math
class Solution:
    def bestCoordinate(self, towers: List[List[int]], radius: int) -> List[int]:
        towers.sort()
        print(towers)
        xi = collections.deque()
        ti = 0
        maxQ = maxX = maxY = 0
        for x in range(towers[0][0], towers[-1][0] + 1):
            while ti < len(towers) and x >= towers[ti][0] - radius:
                xi.append(ti)
                ti += 1
            while xi and towers[xi[0]][0] < x - radius:
                xi.popleft()
            for y in range(51):
                q = 0
                for i in xi:
                    if towers[i][1] < y - radius or towers[i][1] > y + radius:
                        continue
                    d = (towers[i][0] - x) ** 2 + (towers[i][1] - y) ** 2
                    if d <= radius * radius:
                        q += towers[i][2] // (1 + math.sqrt(d))
                if q > maxQ:
                    maxQ = q
                    maxX = x
                    maxY = y
        
        return [maxX, maxY]
