import heapq
import math
class Solution:
    def getSkyline(self, buildings: List[List[int]]) -> List[List[int]]:
        events = sorted([(L, -H, R) for L, R, H in buildings] + [(R, 0, None) for L, R, H in buildings])
        pq = [(0, math.inf)]
        result = []
        for x, negH, R in events:
            while x >= pq[0][1]:
                heapq.heappop(pq)
                
            if negH:
                heapq.heappush(pq, (negH, R))
                
            if not result or result[-1][1] != -pq[0][0]:
                result.append([x, -pq[0][0]])
        return result
