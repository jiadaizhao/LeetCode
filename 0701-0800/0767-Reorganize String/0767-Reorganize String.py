import collections
import heapq
class Solution:
    def reorganizeString(self, S: str) -> str:
        pq = [(-v, k) for k, v in collections.Counter(S).items()]
        heapq.heapify(pq)
        prevCount = 0
        prevChar = ''
        result = []
        while pq:
            count, c = heapq.heappop(pq)
            count = -count
            result.append(c)
            if prevCount > 0:
                heapq.heappush(pq, (-prevCount, prevChar))
            prevCount = count - 1
            prevChar = c
        return ''.join(result) if len(result) == len(S) else ''
