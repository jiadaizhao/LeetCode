import collections
class Solution:
    def minFlips(self, mat: List[List[int]]) -> int:
        m, n = len(mat), len(mat[0])
        state = sum(cell << (i * n + j) for i, row in enumerate(mat) for j, cell in enumerate(row))
        Q = collections.deque([state])
        visited = set([state])
        step = 0
        while Q:
            for _ in range(len(Q)):
                curr = Q.popleft()
                if curr == 0:
                    return step
                for r in range(m):
                    for c in range(n):
                        state = curr ^ (1 << (r * n + c))
                        for nr, nc in (r-1, c), (r+1, c), (r, c-1), (r, c+1):
                            if 0 <= nr < m and 0 <= nc < n:
                                state ^= 1 << (nr * n + nc)
                        if state not in visited:
                            Q.append(state)
                            visited.add(state)
            step += 1
        return -1
