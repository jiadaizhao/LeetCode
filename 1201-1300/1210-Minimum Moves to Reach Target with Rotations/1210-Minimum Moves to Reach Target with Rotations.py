import collections
class Solution:
    def minimumMoves(self, grid) -> int:
        n = len(grid)
        start = (0, 0, 0, 1)
        target = (n - 1, n - 2, n - 1, n - 1)
        move = 0
        visited = set([start])
        Q = collections.deque([start])
        while Q:
            move += 1
            for _ in range(len(Q)):
                r1, c1, r2, c2 = Q.popleft()

                if c1 + 1 < n and grid[r1][c1 + 1] == 0 and c2 + 1 < n and grid[r2][c2 + 1] == 0:
                    npos = (r1, c1 + 1, r2, c2 + 1)
                    if npos == target:
                        return move
                    if npos not in visited:
                        visited.add(npos)
                        Q.append(npos)
                if r1 + 1 < n and grid[r1 + 1][c1] == 0 and r2 + 1 < n and grid[r2 + 1][c2] == 0:
                    npos = (r1 + 1, c1, r2 + 1, c2)
                    if npos == target:
                        return move
                    if npos not in visited:
                        visited.add(npos)
                        Q.append(npos)

                if r1 == r2 and r1 + 1 < n and grid[r1 + 1][c1] == 0 and grid[r2 + 1][c2] == 0:
                    npos = (r1, c1, r2 + 1, c2 - 1)
                    if npos == target:
                        return move
                    if npos not in visited:
                        visited.add(npos)
                        Q.append(npos)

                if c1 == c2 and c1 + 1 < n and grid[r1][c1 + 1] == 0 and grid[r2][c2 + 1] == 0:
                    npos = (r1, c1, r2 - 1, c2 + 1)
                    if npos == target:
                        return move
                    if npos not in visited:
                        visited.add(npos)
                        Q.append(npos)

        return -1
