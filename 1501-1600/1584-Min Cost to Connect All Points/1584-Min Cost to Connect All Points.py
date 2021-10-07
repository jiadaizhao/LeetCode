import heapq
class Solution:
    def minCostConnectPoints(self, points: List[List[int]]) -> int:
        pq = []
        n = len(points)
        for i in range(n):
            for j in range(i + 1, n):
                pq.append((abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]), i, j))
        heapq.heapify(pq)
        parent = list(range(n))
        def findParent(x):
            while parent[x] != x:
                parent[x] = parent[parent[x]]
                x = parent[x]
            return x
        count = result = 0
        while pq:
            dist, i, j = heapq.heappop(pq)
            pi = findParent(i)
            pj = findParent(j)
            if pi != pj:
                result += dist
                parent[pj] = parent[pi]
                count += 1
                if count == n - 1:
                    break
        return result
