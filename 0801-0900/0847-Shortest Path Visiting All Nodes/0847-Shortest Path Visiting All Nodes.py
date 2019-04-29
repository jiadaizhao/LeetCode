import collections
import math
class Solution:
    def shortestPathLength(self, graph: List[List[int]]) -> int:
        n = len(graph)
        dp = [[math.inf] * (1 << n) for _ in range(n)]
        Q = collections.deque()
        for i in range(n):
            dp[i][1 << i] = 0
            Q.append((i, 1 << i))
            
        while Q:
            curr, mask = Q.popleft()
            for next in graph[curr]:
                nextMask = mask | (1 << next)
                if dp[next][nextMask] > dp[curr][mask] + 1:
                    dp[next][nextMask] = dp[curr][mask] + 1
                    Q.append((next, nextMask))
        
        return min(list(zip(*dp))[-1])
