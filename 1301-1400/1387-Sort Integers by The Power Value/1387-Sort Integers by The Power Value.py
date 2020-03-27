from functools import lru_cache
import heapq
class Solution:
    def getKth(self, lo: int, hi: int, k: int) -> int:
        @lru_cache(None)
        def computeStep(x):
            step = 0
            while x != 1:
                if x & 1:
                    x = 3 * x + 1
                else:
                    x >>= 1
                step += 1
            return step
        
        pq = [(computeStep(x), x) for x in range(lo, hi + 1)]
        heapq.heapify(pq)
        for _ in range(k):
            result = heapq.heappop(pq)[1]
        return result
