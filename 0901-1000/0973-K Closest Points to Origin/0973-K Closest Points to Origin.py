import heapq
class Solution:
    def kClosest(self, points: List[List[int]], K: int) -> List[List[int]]:
        pq = []
        for i, (x, y) in enumerate(points):
            heapq.heappush(pq, (-x*x -y*y, i))
            if len(pq) > K:
                heapq.heappop(pq)

        return [points[i] for _, i in pq]
