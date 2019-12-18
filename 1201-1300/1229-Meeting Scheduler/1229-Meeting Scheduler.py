class Solution:
    def minAvailableDuration(self, slots1: List[List[int]], slots2: List[List[int]], duration: int) -> List[int]:
        slots1.sort()
        slots2.sort()
        i = j = 0
        while i < len(slots1) and j < len(slots2):
            start = max(slots1[i][0], slots2[j][0])
            end = min(slots1[i][1], slots2[j][1])
            if start + duration <= end:
                return [start, start + duration]
            if slots1[i][1] <= slots2[j][1]:
                i += 1
            else:
                j += 1
        return []


import heapq
class Solution:
    def minAvailableDuration(self, slots1: List[List[int]], slots2: List[List[int]], duration: int) -> List[int]:
        pq = []
        for s in slots1:
            if s[1] - s[0] >= duration:
                heapq.heappush(pq, s)
        for s in slots2:
            if s[1] - s[0] >= duration:
                heapq.heappush(pq, s)
                
        while len(pq) > 1:
            start, end = heapq.heappop(pq)
            if pq[0][0] + duration <= end:
                return [pq[0][0], pq[0][0] + duration]
        return []
