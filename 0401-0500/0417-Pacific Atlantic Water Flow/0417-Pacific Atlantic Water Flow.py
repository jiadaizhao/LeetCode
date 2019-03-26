import collections
class Solution:
    def pacificAtlantic(self, matrix: List[List[int]]) -> List[List[int]]:
        m = len(matrix)
        if m == 0:
            return []
        n = len(matrix[0])
        if n == 0:
            return []
        visitedTimes = [[0] * n for _ in range(m)]
        
        def bfs(start):
            Q = collections.deque(start)
            visited = [[False]*n for _ in range(m)]
            for row, col, height in start:
                visited[row][col] = True
                visitedTimes[row][col] += 1
            while Q:
                row, col, height = Q.popleft()
                for nr, nc in (row-1, col), (row+1, col), (row, col-1), (row, col+1):
                    if 0 <= nr < m and 0 <= nc < n and not visited[nr][nc] and matrix[nr][nc] >= height:
                        visited[nr][nc] = True
                        visitedTimes[nr][nc] += 1
                        Q.append((nr, nc, matrix[nr][nc]))
                        
        bfs([[i, 0, matrix[i][0]] for i in range(m)] + [[0, j, matrix[0][j]] for j in range(1, n)])
        bfs([[i, n - 1, matrix[i][n - 1]] for i in range(m)] + [[m - 1, j, matrix[m - 1][j]] for j in range(n - 1)])
        return [[row, col] for row in range(m) for col in range(n) if visitedTimes[row][col] == 2]
