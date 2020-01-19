import collections
class Solution:
    def wallsAndGates(self, rooms: List[List[int]]) -> None:
        """
        Do not return anything, modify rooms in-place instead.
        """
        if not rooms:
            return
        m, n = len(rooms), len(rooms[0])
        INT_MAX = (1 << 31) - 1
        Q = collections.deque()
        for i in range(m):
            for j in range(n):
                if rooms[i][j] == 0:
                    Q.append((i, j))
        step = 0
        while Q:
            step += 1
            for _ in range(len(Q)):
                r, c = Q.popleft()
                for nr, nc in (r-1, c), (r+1, c), (r, c-1), (r, c+1):
                    if 0 <= nr < m and 0 <= nc < n and rooms[nr][nc] == INT_MAX:
                        Q.append((nr, nc))
                        rooms[nr][nc] = step
