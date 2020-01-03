import collections
class Solution:
    def hasPath(self, maze: List[List[int]], start: List[int], destination: List[int]) -> bool:
        m, n = len(maze), len(maze[0])
        Q = collections.deque([start])
        visited = [[False] * n for _ in range(m)]
        visited[start[0]][start[1]] = True
        dr = [-1, 1, 0, 0]
        dc = [0, 0, -1, 1]
        while Q:
            r, c = Q.popleft()
            for i in range(4):
                nr = r + dr[i]
                nc = c + dc[i]
                while 0 <= nr < m and 0 <= nc < n and maze[nr][nc] == 0:
                    nr += dr[i]
                    nc += dc[i]
                nr -= dr[i]
                nc -= dc[i]
                if [nr, nc] == destination:
                    return True
                if not visited[nr][nc]:
                    Q.append([nr, nc])
                    visited[nr][nc] = True
        
        return False
