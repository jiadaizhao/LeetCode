import heapq
class Solution:
    def powerfulIntegers(self, x: int, y: int, bound: int) -> List[int]:
        result = []
        pq = [(2, 1, 1)]
        while pq:
            s, i, j = heapq.heappop(pq)
            if s > bound:
                break
            if not result or s != result[-1]:
                result.append(s)
            if x != 1:
                heapq.heappush(pq, (i * x + j, i * x, j))
            if y != 1:
                heapq.heappush(pq, (i + j * y, i, j * y))
        return result            
