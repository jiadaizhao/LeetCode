import collections

class Solution:
    def maxDistance(self, grid: List[List[int]]) -> int:
        N = len(grid)
        Q = collections.deque()
        visited = set()
        for i in range(N):
            for j in range(N):
                if grid[i][j] == 1:
                    Q.append((i, j))
                    visited.add(i * N + j)

        maxD = -1
        while Q:
            for _ in range(len(Q)):
                row, col = Q.popleft()
                for nr, nc in (row - 1, col), (row + 1, col), (row, col - 1), (row, col + 1):
                    if 0 <= nr < N and 0 <= nc < N and (nr * N + nc) not in visited:
                        Q.append((nr, nc))
                        visited.add(nr * N + nc)
            maxD += 1

        return -1 if maxD <= 0 else maxD
