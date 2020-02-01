import collections
import math
class Solution:
    def shortestPathLength(self, graph: List[List[int]]) -> int:
        n = len(graph)
        dp = [[math.inf] * n for _ in range(1 << n)]
        Q = collections.deque()
        for i in range(n):
            dp[1 << i][i] = 0
            Q.append((1 << i, i))
            
        while Q:
            mask, curr = Q.popleft()
            for next in graph[curr]:
                nextMask = mask | (1 << next)
                if dp[nextMask][next] > dp[mask][curr] + 1:
                    dp[nextMask][next] = dp[mask][curr] + 1
                    Q.append((nextMask, next))
        
        return min(dp[-1])
