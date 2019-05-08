import heapq
class Solution:
    def minRefuelStops(self, target: int, startFuel: int, stations: List[List[int]]) -> int:
        dist = startFuel
        stop = i = 0
        pq = []
        while dist < target:
            stop += 1
            while i < len(stations) and dist >= stations[i][0]:
                heapq.heappush(pq, -stations[i][1])
                i += 1

            if not pq:
                return -1

            dist -= heapq.heappop(pq)
        return stop
