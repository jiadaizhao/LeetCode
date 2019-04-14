# Hadlock's Algorithm
import collections
class Solution:
    def cutOffTree(self, forest: List[List[int]]) -> int:
        m = len(forest)
        if m == 0:
            return 0
        n = len(forest[0])
        trees = sorted((v, r, c) for r, row in enumerate(forest) for c, v in enumerate(row) if v > 1)
        sr = sc = total = 0
        def search(sr, sc, tr, tc):
            processed = set()
            dq = collections.deque([(0, sr, sc)])
            while dq:
                detours, r, c = dq.popleft()
                if r*n + c not in processed:
                    processed.add(r*n + c)
                    if r == tr and c == tc:
                        return abs(sr - tr) + abs(sc - tc) + 2*detours
                    for nr, nc, closer in (r-1, c, r>tr), (r+1, c, r<tr), (r, c-1, c>tc), (r, c+1, c<tc):
                        if 0 <= nr < m and 0 <= nc < n and forest[nr][nc]:
                            if closer:
                                dq.appendleft((detours, nr, nc))
                            else:
                                dq.append((detours+1, nr, nc))
            return -1
            
        for _, tr, tc in trees:
            d = search(sr, sc, tr, tc)
            if d < 0:
                return -1
            total += d
            sr, sc = tr, tc
        return total 
