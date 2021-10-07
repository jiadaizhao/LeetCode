class Solution:
    def maxNumEdgesToRemove(self, n: int, edges: List[List[int]]) -> int:
        parent = list(range(n + 1))
        def findParent(i):
            while parent[i] != i:
                parent[i] = parent[parent[i]]
                i = parent[i]
            return i
        
        def union(u, v):
            pu = findParent(u)
            pv = findParent(v)
            if pu != pv:
                parent[pv] = pu
                return 1
            else:
                return 0
        
        e1 = e2 = result = 0
        for t, u, v in edges:
            if t == 3:
                if union(u, v):
                    e1 += 1
                    e2 += 1
                else:
                    result += 1
        
        parentOrig = parent[:]
        for t, u, v in edges:
            if t == 1:
                if union(u, v):
                    e1 += 1
                else:
                    result += 1           
        
        parent = parentOrig
        for t, u, v in edges:
            if t == 2:
                if union(u, v):
                    e2 += 1
                else:
                    result += 1
        return result if e1 == e2 == n - 1 else -1
