import collections
class Solution:
    def gridIllumination(self, N: int, lamps: List[List[int]], queries: List[List[int]]) -> List[int]:
        row = collections.Counter()
        col = collections.Counter()
        diag = collections.Counter()
        anti = collections.Counter()
        locations = set()
        for x, y in lamps:
            row[y] += 1
            col[x] += 1
            diag[x - y] += 1
            anti[x + y] += 1
            locations.add((x, y))
            
        result = [0] * len(queries)
        for i, (x, y) in enumerate(queries):
            if row[y] or col[x] or diag[x - y] or anti[x + y]:
                result[i] = 1
                for nx, ny in (x-1, y-1), (x-1, y), (x-1, y+1), (x, y-1), (x, y+1), (x, y), (x+1, y-1), (x+1, y), (x+1, y+1):
                    if 0 <= nx < N and 0 <= ny < N and (nx, ny) in locations:
                        locations.remove((nx, ny))
                        row[ny] -= 1
                        col[nx] -= 1
                        diag[nx - ny] -= 1
                        anti[nx + ny] -= 1
        
        return result
