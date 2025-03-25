import heapq
class Solution:
    def eatenApples(self, apples: List[int], days: List[int]) -> int:
        pq = []
        i = num = 0
        while i < len(apples) or pq:
            if i < len(apples) and apples[i] > 0:
                heapq.heappush(pq, [i + days[i], apples[i]])
            while pq and pq[0][0] <= i :
                heapq.heappop(pq)
            if pq:
                num += 1
                pq[0][1] -= 1
                if pq[0][1] == 0:
                    heapq.heappop(pq)
            i += 1
        return num
