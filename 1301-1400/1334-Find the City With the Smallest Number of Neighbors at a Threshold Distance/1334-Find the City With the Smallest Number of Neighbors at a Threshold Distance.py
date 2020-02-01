import math
class Solution:
    def findTheCity(self, n: int, edges: List[List[int]], distanceThreshold: int) -> int:
        dist = [[math.inf] * n for _ in range(n)]
        for i, j, w in edges:
            dist[i][j] = dist[j][i] = w
            
        for i in range(n):
            dist[i][i] = 0
            
        for k in range(n):
            for i in range(n):
                for j in range(n):
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j])

        counts = [sum(d <= distanceThreshold for d in dist[i]) for i in range(n)]
        minIndex = 0
        for i in range(1, n):
            if counts[i] <= counts[minIndex]:
                minIndex = i
        return minIndex
