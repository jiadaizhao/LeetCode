import collections
import heapq
class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        table = collections.Counter(nums)
        pq = []
        for num, count in table.items():
            heapq.heappush(pq, (count, num))
            if len(pq) > k:
                heapq.heappop(pq)
        
        result = []
        while pq:
            result.append(heapq.heappop(pq)[1])

        return result[::-1]
