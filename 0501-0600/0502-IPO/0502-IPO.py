import heapq
class Solution:
    def findMaximizedCapital(self, k: int, W: int, Profits: List[int], Capital: List[int]) -> int:
        cappq = [(cap, i) for i, cap in enumerate(Capital)]
        heapq.heapify(cappq)
        profitpq = []
        for _ in range(k):
            while cappq and cappq[0][0] <= W:
                cap, index = heapq.heappop(cappq)
                heapq.heappush(profitpq, -Profits[index])
                
            if profitpq:
                W -= heapq.heappop(profitpq)
            else:
                break
        return W
