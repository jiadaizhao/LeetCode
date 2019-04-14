import heapq
import collections
class Cell:
    def __init__(self, count, word):
        self.count = count
        self.word = word
        
    def __lt__(self, other):
        if self.count == other.count:
            return self.word > other.word
        return self.count < other.count        

class Solution:
    def topKFrequent(self, words: List[str], k: int) -> List[str]:
        table = collections.Counter(words)
        pq = []
        for word, count in table.items():
            heapq.heappush(pq, Cell(count, word))
            if len(pq) > k:
                heapq.heappop(pq)
                
        return [heapq.heappop(pq).word for _ in range(k)][::-1]
