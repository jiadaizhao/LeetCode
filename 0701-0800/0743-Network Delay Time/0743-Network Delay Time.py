import collections
import heapq
class Solution:
    def networkDelayTime(self, times: List[List[int]], N: int, K: int) -> int:
        graph = collections.defaultdict(list)
        for u, v, w in times:
            graph[u].append((v, w))
        pq = [(0, K)]
        distance = {}
        while pq:
            d, node = heapq.heappop(pq)
            if node not in distance:
                distance[node] = d
                for neighbor, d2 in graph[node]:
                    if neighbor not in distance:
                        heapq.heappush(pq, (d + d2, neighbor))
        return max(distance.values()) if len(distance) == N else -1 
