import collections
import heapq
class Solution:
    def rearrangeString(self, s: str, k: int) -> str:
        if not s or k == 0:
            return s
        table = collections.Counter(s)
        pq = [(-val, key) for key, val in table.items()]
        heapq.heapify(pq)
        result = []
        left = len(s)
        while pq:
            dist = min(left, k)
            if dist > len(pq):
                return ''
            temp = []
            for i in range(dist):
                negCount, c = heapq.heappop(pq)
                result.append(c)
                left -= 1
                if negCount != -1:
                    temp.append((negCount + 1, c))
                    
            pq += temp
            heapq.heapify(pq)
        return ''.join(result)
