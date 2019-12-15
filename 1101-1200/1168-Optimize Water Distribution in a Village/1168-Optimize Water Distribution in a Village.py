class Solution:
    def minCostToSupplyWater(self, n: int, wells: List[int], pipes: List[List[int]]) -> int:
        parent = [i for i in range(1 + n)]
        def findParent(x):
            while parent[x] != x:
                parent[x] = parent[parent[x]]
                x = parent[x]
            return x
        
        edges = [(c, 0, i) for i, c in enumerate(wells, 1)]
        edges += [(c, i, j) for i, j, c in pipes]
        cost = 0
        for c, x, y in sorted(edges):
            px = findParent(x)
            py = findParent(y)
            if px != py:
                cost += c
                parent[py] = px
                n -= 1
                if n == 0:
                    break
        
        return cost
