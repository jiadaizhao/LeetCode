import heapq
class Solution:
    def trapRainWater(self, heightMap: List[List[int]]) -> int:
        m = len(heightMap)
        if m == 0:
            return 0
        n = len(heightMap[0])
        if n == 0:
            return 0
        visited = [[False]*n for _ in range(m)]
        pq = []
        for i in range(m):
            heapq.heappush(pq, (heightMap[i][0], i, 0))
            visited[i][0] = True
            if n > 1:
                heapq.heappush(pq, (heightMap[i][n - 1], i, n - 1))
                visited[i][n - 1] = True
        
        for j in range(1, n - 1):
            heapq.heappush(pq, (heightMap[0][j], 0, j))
            visited[0][j] = True
            if m > 1:
                heapq.heappush(pq, (heightMap[m - 1][j], m - 1, j))
                visited[m - 1][j] = True
        vol = 0        
        while pq:
            h, row, col = heapq.heappop(pq)
            for nr, nc in (row-1, col), (row+1, col), (row, col-1), (row, col+1):
                if 0 <= nr < m and 0 <= nc < n and (not visited[nr][nc]):
                    heapq.heappush(pq, (max(h, heightMap[nr][nc]), nr, nc))
                    visited[nr][nc] = True
                    vol += max(h - heightMap[nr][nc], 0)
        return vol
