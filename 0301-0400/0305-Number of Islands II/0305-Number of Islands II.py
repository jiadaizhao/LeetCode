class Solution:
    def numIslands2(self, m: int, n: int, positions: List[List[int]]) -> List[int]:
        result = [0] * len(positions)
        parent = [-1] * (m * n)
        count = 0
        def findParent(x):
            while parent[x] != x:
                parent[x] = parent[parent[x]]
                x = parent[x]
            return x

        for i, (r, c) in enumerate(positions):
            if parent[r * n + c] == -1:
                parent[r * n + c] = r * n + c
                count += 1
                for nr, nc in (r-1, c), (r+1, c), (r, c-1), (r, c+1):
                    if 0 <= nr < m and 0 <= nc < n and parent[nr * n + nc] != -1:
                        p1 = findParent(r * n + c)
                        p2 = findParent(nr * n + nc)
                        if p1 != p2:
                            count -= 1
                            parent[p2] = p1
            result[i] = count
        return result
