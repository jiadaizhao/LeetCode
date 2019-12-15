import collections
# BFS
class Solution:
    def minKnightMoves(self, x: int, y: int) -> int:
        if x == 0 and y == 0:
            return 0
        Q = collections.deque([(0, 0)])
        visited = set([(0, 0)])
        step = 0
        x, y = abs(x), abs(y)
        while Q:
            step += 1
            for _ in range(len(Q)):
                cx, cy = Q.popleft()
                for nx, ny in ((cx-2, cy-1), (cx-2, cy+1), (cx-1, cy-2), (cx-1, cy+2),
                               (cx+1, cy-2), (cx+1, cy+2), (cx+2, cy-1), (cx+2, cy+1)):
                    if nx == x and ny == y:
                        return step
                    if (nx, ny) not in visited and -2 <= nx <= x + 2 and -2 <= ny <= y + 2:
                        visited.add((nx, ny))
                        Q.append((nx, ny))
        return -1

# Bidirection BFS
class Solution2:
    def minKnightMoves(self, x: int, y: int) -> int:
        if x == 0 and y == 0:
            return 0
        
        step = 0
        x, y = abs(x), abs(y)
        visitedBegin = set([(0, 0)])
        visitedEnd = set([(x, y)])
        visited = set([(0, 0)])
        while visitedBegin and visitedEnd:
            if len(visitedBegin) > len(visitedEnd):
                visitedBegin, visitedEnd = visitedEnd, visitedBegin
            step += 1
            temp = set()
            for cx, cy in visitedBegin:
                for nx, ny in ((cx-2, cy-1), (cx-2, cy+1), (cx-1, cy-2), (cx-1, cy+2),
                               (cx+1, cy-2), (cx+1, cy+2), (cx+2, cy-1), (cx+2, cy+1)):
                    if (nx, ny) in visitedEnd:
                        return step
                    if (nx, ny) not in visited and -2 <= nx <= x + 2 and -2 <= ny <= y + 2:
                        visited.add((nx, ny))
                        temp.add((nx, ny))
            visitedBegin = temp
        return -1


import math
class Solution3:
    def minKnightMoves(self, x: int, y: int) -> int:
        if x == 0 and y == 0:
            return 0
        x, y = abs(x), abs(y)
        if x > y:
            x, y = y, x
        if x == 1 and y == 1:
            return 2
        if x == 2 and y == 2:
            return 4
        if x + y == 1:
            return 3
        m = max(math.ceil(y / 2), math.ceil((x + y) / 3)) 
        return m + ((m + x + y) & 1)
