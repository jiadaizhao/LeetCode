import heapq
import math
# Dijkstra
class Solution:
    def findShortestWay(self, maze: List[List[int]], ball: List[int], hole: List[int]) -> str:
        m, n = len(maze), len(maze[0])
        pq = [[0, ''] + ball]
        distance = [[math.inf] * n for _ in range(m)]
        distance[ball[0]][ball[1]] = 0
        dr = [-1, 1, 0, 0]
        dc = [0, 0, -1, 1]
        direction = ['u', 'd', 'l', 'r']
        while pq:
            d, di, r, c = heapq.heappop(pq)
            if [r, c] == hole:
                return di
            for i in range(4):
                nr = r + dr[i]
                nc = c + dc[i]
                nd = d + 1
                while 0 <= nr < m and 0 <= nc < n and maze[nr][nc] == 0 and not [nr, nc] == hole:
                    nr += dr[i]
                    nc += dc[i]
                    nd += 1
                if not [nr, nc] == hole: 
                    nr -= dr[i]
                    nc -= dc[i]
                    nd -= 1

                if distance[nr][nc] >= nd and not [nr, nc] == [r, c]:
                    heapq.heappush(pq, [nd, di + direction[i], nr, nc])
                    distance[nr][nc] = nd
        
        return 'impossible'


# A*
class Solution:
    def findShortestWay(self, maze: List[List[int]], ball: List[int], hole: List[int]) -> str:
        m, n = len(maze), len(maze[0])
        pq = [[abs(hole[0] - ball[0]) + abs(hole[1] - ball[1]), 0, ''] + ball]
        distance = [[math.inf] * n for _ in range(m)]
        distance[ball[0]][ball[1]] = 0
        dr = [-1, 1, 0, 0]
        dc = [0, 0, -1, 1]
        direction = ['u', 'd', 'l', 'r']
        while pq:
            _, d, di, r, c = heapq.heappop(pq)
            if [r, c] == hole:
                return di
            for i in range(4):
                nr = r + dr[i]
                nc = c + dc[i]
                nd = d + 1
                while 0 <= nr < m and 0 <= nc < n and maze[nr][nc] == 0 and not [nr, nc] == hole:
                    nr += dr[i]
                    nc += dc[i]
                    nd += 1
                if not [nr, nc] == hole: 
                    nr -= dr[i]
                    nc -= dc[i]
                    nd -= 1

                if distance[nr][nc] >= nd and not [nr, nc] == [r, c]:
                    heapq.heappush(pq, [nd + abs(hole[0] - nr) + abs(hole[1] - nc), nd, di + direction[i], nr, nc])
                    distance[nr][nc] = nd
        
        return 'impossible'
