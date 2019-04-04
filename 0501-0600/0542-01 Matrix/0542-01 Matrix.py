import collections
import math
class Solution:
    def updateMatrix(self, matrix: List[List[int]]) -> List[List[int]]:
        if not matrix:
            return []
        m = len(matrix)
        n = len(matrix[0])
        dist = [[math.inf]*n for _ in range(m)]
        Q = collections.deque()
        for i in range(m):
            for j in range(n):
                if matrix[i][j] == 0:
                    dist[i][j] = 0
                    Q.append((i, j))
        
        while Q:
            row, col = Q.popleft()
            
            for nr, nc in (row-1, col), (row+1, col), (row, col-1), (row, col+1):
                if 0 <= nr < m and 0 <= nc < n and dist[nr][nc] > dist[row][col] + 1:
                    dist[nr][nc] = dist[row][col] + 1
                    # print(row, col, nr, nc, dist[nr][nc])
                    Q.append((nr, nc))
                    
        return dist
