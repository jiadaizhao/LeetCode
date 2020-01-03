import heapq
import math
# Dijkstra
class Solution:
    def shortestDistance(self, maze: List[List[int]], start: List[int], destination: List[int]) -> int:
        m, n = len(maze), len(maze[0])
        pq = [[0] + start]
        distance = [[math.inf] * n for _ in range(m)]
        distance[start[0]][start[1]] = 0
        dr = [-1, 1, 0, 0]
        dc = [0, 0, -1, 1]
        while pq:
            d, r, c = heapq.heappop(pq)
            if [r, c] == destination:
                return d
            for i in range(4):
                nr = r + dr[i]
                nc = c + dc[i]
                nd = d + 1
                while 0 <= nr < m and 0 <= nc < n and maze[nr][nc] == 0:
                    nr += dr[i]
                    nc += dc[i]
                    nd += 1
                nr -= dr[i]
                nc -= dc[i]
                nd -= 1

                if distance[nr][nc] > nd:
                    heapq.heappush(pq, [nd, nr, nc])
                    distance[nr][nc] = nd
        
        return -1


# A*
class Solution:
    def shortestDistance(self, maze: List[List[int]], start: List[int], destination: List[int]) -> int:
        m, n = len(maze), len(maze[0])
        pq = [[abs(destination[0] - start[0]) + abs(destination[1] - start[1]), 0] + start]
        distance = [[math.inf] * n for _ in range(m)]
        distance[start[0]][start[1]] = 0
        dr = [-1, 1, 0, 0]
        dc = [0, 0, -1, 1]
        while pq:
            _, d, r, c = heapq.heappop(pq)
            if [r, c] == destination:
                return d
            for i in range(4):
                nr = r + dr[i]
                nc = c + dc[i]
                nd = d + 1
                while 0 <= nr < m and 0 <= nc < n and maze[nr][nc] == 0:
                    nr += dr[i]
                    nc += dc[i]
                    nd += 1
                nr -= dr[i]
                nc -= dc[i]
                nd -= 1

                if distance[nr][nc] > nd:
                    heapq.heappush(pq, [nd + abs(destination[0] - nr) + abs(destination[1] - nc), nd, nr, nc])
                    distance[nr][nc] = nd
        
        return -1
