import heapq
class Solution:
    def assignBikes(self, workers: List[List[int]], bikes: List[List[int]]) -> int:
        pq = [(0, 0, 0)]
        visited = set()
        while pq:
            dist, wi, mask = heapq.heappop(pq)
            if wi == len(workers):
                return dist
            if mask in visited:
                continue
            visited.add(mask)
            for j in range(len(bikes)):
                if (1 << j) & mask == 0:
                    nmask = (1 << j) | mask
                    if nmask in visited:
                        continue
                    d = abs(workers[wi][0] - bikes[j][0]) + abs(workers[wi][1] - bikes[j][1])
                    heapq.heappush(pq, (dist + d, wi + 1, nmask))

# Slower
import math
class Solution2:
    def assignBikes(self, workers: List[List[int]], bikes: List[List[int]]) -> int:
        dp = [[math.inf] * (1 << len(bikes)) for _ in range(1 + len(workers))]
        minDist = math.inf
        dp[0][0] = 0
        for i in range(1, 1 + len(workers)):
            for mask in range(1, 1 << len(bikes)):
                for j in range(len(bikes)):
                    if (1 << j) & mask != 0:
                        prev = mask ^ (1 << j)
                        d = abs(workers[i - 1][0] - bikes[j][0]) + abs(workers[i - 1][1] - bikes[j][1])
                        dp[i][mask] = min(dp[i][mask], dp[i - 1][prev] + d)
                        if i == len(workers):
                            minDist = min(minDist, dp[i][mask])

        return minDist
