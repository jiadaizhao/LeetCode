import heapq
class Solution:
    def kClosest(self, points: List[List[int]], K: int) -> List[List[int]]:
        pq = []
        for i, (x, y) in enumerate(points):
            heapq.heappush(pq, (-x*x -y*y, i))
            if len(pq) > K:
                heapq.heappop(pq)

        return [points[i] for _, i in pq]

import random
class Solution:
    def kClosest(self, points: List[List[int]], K: int) -> List[List[int]]:
        def partition(start, end):
            pivot = random.randint(start, end)
            points[pivot], points[end] = points[end], points[pivot]
            j = start
            for i in range(start, end):
                if points[i][0]**2 + points[i][1]**2 <= points[end][0]**2 + points[end][1]**2:
                    points[j], points[i] = points[i], points[j]
                    j += 1
            points[j], points[end] = points[end], points[j]
            return j
        
        start = 0
        end = len(points) - 1
        while True:
            index = partition(start, end)
            if index < K - 1:
                start = index + 1
            elif index > K - 1:
                end = index - 1
            else:
                break
        return points[:K]
