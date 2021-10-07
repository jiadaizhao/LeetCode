class Solution:
    def areConnected(self, n: int, threshold: int, queries: List[List[int]]) -> List[bool]:
        parent = list(range(n + 1))
        def findParent(x):
            while parent[x] != x:
                parent[x] = parent[parent[x]]
                x = parent[x]
            return x
        def union(a, b):
            pa = findParent(a)
            pb = findParent(b)
            if pa != pb:
                parent[pb] = pa
                
        for i in range(threshold + 1, n):
            m = 2
            while m * i <= n:
                union(i, m * i)
                m += 1
        return [findParent(a) == findParent(b) for a, b in queries]
