import collections
import heapq
class Solution:
    def highFive(self, items: List[List[int]]) -> List[List[int]]:
        table = collections.defaultdict(list)
        for i, score in items:
            heapq.heappush(table[i], score)
            if len(table[i]) > 5:
                heapq.heappop(table[i])
        return [[i, sum(table[i]) // len(table[i])] for i in sorted(table)]
