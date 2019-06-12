import collections
import heapq
class Solution:
    def rearrangeBarcodes(self, barcodes: List[int]) -> List[int]:
        pq = [(-val, key) for key, val in collections.Counter(barcodes).items()]
        heapq.heapify(pq)
        result = [0] * len(barcodes)
        preKey = preVal = -1
        for i in range(len(barcodes)):
            val, key = heapq.heappop(pq)
            result[i] = key
            val += 1
            if preKey != -1 and preVal != 0:
                heapq.heappush(pq, (preVal, preKey))
            preKey = key
            preVal = val
        return result


class Solution2:
    def rearrangeBarcodes(self, barcodes: List[int]) -> List[int]:
        result = [0] * len(barcodes)
        pos = 0
        for key, val in collections.Counter(barcodes).most_common():
            for _ in range(val):
                result[pos] = key
                pos = pos + 2 if pos + 2 < len(barcodes) else 1

        return result
