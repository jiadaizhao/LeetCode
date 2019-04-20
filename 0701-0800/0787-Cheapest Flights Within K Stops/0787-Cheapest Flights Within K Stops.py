import collections
import heapq
class Solution:
    def findCheapestPrice(self, n: int, flights: List[List[int]], src: int, dst: int, K: int) -> int:
        weights = collections.defaultdict(dict)
        for f in flights:
            weights[f[0]][f[1]] = f[2]
        pq = [(0, 0, src)]
        dist = {}
        while pq:
            cost, stop, city = heapq.heappop(pq)
            if city == dst:
                return cost
            if (stop, city) in dist:
                continue
            dist[(stop, city)] = cost
            if stop <= K:
                for neighbor, weight in weights[city].items():
                    heapq.heappush(pq, (cost + weight, stop + 1, neighbor))
        
        return -1
