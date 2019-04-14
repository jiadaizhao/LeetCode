class Solution:
    def findRedundantConnection(self, edges: List[List[int]]) -> List[int]:
        parent = [i for i in range(len(edges))]
        def findParent(x):
            while parent[x] != x:
                parent[x] = parent[parent[x]]
                x = parent[x]
            return x
        for edge in edges:
            p1 = findParent(edge[0] - 1)
            p2 = findParent(edge[1] - 1)
            if p1 == p2:
                return edge
            parent[p2] = p1
