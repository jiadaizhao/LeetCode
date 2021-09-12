import collections
import heapq
class Solution:
    def maxProbability(self, n: int, edges: List[List[int]], succProb: List[float], start: int, end: int) -> float:
        graph = collections.defaultdict(list)
        for i, (a, b) in enumerate(edges):
            graph[a].append((b, i))
            graph[b].append((a, i))
        prob = [0] * n
        prob[start] = 1
        pq = [(-1, start)]
        while pq:
            p, index = heapq.heappop(pq)
            if index == end:
                return -p
            for node, i in graph[index]:
                if -p * succProb[i] > prob[node]:
                    prob[node] = -p * succProb[i]
                    heapq.heappush(pq, (-prob[node], node))
        return 0
