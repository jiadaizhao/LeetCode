import math
import heapq
class Solution:
    def mincostToHireWorkers(self, quality: List[int], wage: List[int], K: int) -> float:
        minCost = math.inf
        ratioAndQuality = sorted((w/q, q) for q, w in zip(quality, wage))
        pq = []
        qs = 0
        for ratio, q in ratioAndQuality:
            qs += q
            heapq.heappush(pq, -q)
            if len(pq) > K:
                qs += heapq.heappop(pq)
            if len(pq) == K:
                minCost = min(minCost, qs*ratio)
        return minCost
