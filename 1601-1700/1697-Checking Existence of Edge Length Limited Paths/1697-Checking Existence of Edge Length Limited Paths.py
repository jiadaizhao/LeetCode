class Solution:
    def distanceLimitedPathsExist(self, n: int, edgeList: List[List[int]], queries: List[List[int]]) -> List[bool]:
        queries = sorted((l, p, q, i) for i, (p, q, l) in enumerate(queries))
        edges = sorted((d, u, v) for u, v, d in edgeList)
        parent = list(range(n))
        def findParent(x):
            while parent[x] != x:
                parent[x] = parent[parent[x]]
                x = parent[x]
            return x
        result = [False] * len(queries)
        j = 0
        for l, p, q, i in queries:
            while j < len(edges) and edges[j][0] < l:
                p1 = findParent(edges[j][1])
                p2 = findParent(edges[j][2])
                if p1 != p2:
                    parent[p2] = p1
                j += 1
            if findParent(p) == findParent(q):
                result[i] = True
        return result
