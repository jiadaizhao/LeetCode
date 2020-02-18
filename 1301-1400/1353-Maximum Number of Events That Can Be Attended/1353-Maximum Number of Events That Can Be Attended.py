import heapq
class Solution:
    def maxEvents(self, events: List[List[int]]) -> int:
        events.sort()
        pq = []
        i = day = count = 0
        while pq or i < len(events):
            if not pq:
                day = events[i][0]
            while i < len(events) and events[i][0] <= day:
                heapq.heappush(pq, events[i][1])
                i += 1
            heapq.heappop(pq)
            count += 1
            day += 1
            while pq and pq[0] < day:
                heapq.heappop(pq)
        return count
