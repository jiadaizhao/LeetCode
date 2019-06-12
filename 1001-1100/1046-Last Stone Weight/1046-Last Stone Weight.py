import heapq
class Solution:
    def lastStoneWeight(self, stones: List[int]) -> int:
        pq = [-stone for stone in stones]
        heapq.heapify(pq)
        while len(pq) > 1:
            y = heapq.heappop(pq)
            x = heapq.heappop(pq)
            if x != y:
                heapq.heappush(pq, y - x)
        return -pq[0] if pq else 0
