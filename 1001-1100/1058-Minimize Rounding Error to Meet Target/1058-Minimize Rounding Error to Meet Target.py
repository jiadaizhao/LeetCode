import heapq
import math
class Solution:
    def minimizeError(self, prices: List[str], target: int) -> str:
        pq = []
        error = 0
        for p in map(float, prices):
            f = math.floor(p)
            c = math.ceil(p)
            target -= f
            error += p - f
            if f != c:
                heapq.heappush(pq, (c - p) - (p - f))
        if target < 0 or len(pq) < target:
            return '-1'
        while target > 0:
            error += heapq.heappop(pq)
            target -= 1
        return '{:.3f}'.format(error)
