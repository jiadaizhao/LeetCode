class Solution:
    def validTree(self, n: int, edges: List[List[int]]) -> bool:
        if len(edges) != n - 1:
            return False
        parent = [i for i in range(n)]
        def findParent(x):
            while parent[x] != x:
                parent[x] = parent[parent[x]]
                x = parent[x]
            return x
        for u, v in edges:
            pu = findParent(u)
            pv = findParent(v)
            if pu != pv:
                parent[pv] = pu
            else:
                return False
        return True
