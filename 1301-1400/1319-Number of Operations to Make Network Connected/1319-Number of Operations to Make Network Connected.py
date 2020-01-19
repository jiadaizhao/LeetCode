class Solution:
    def makeConnected(self, n: int, connections: List[List[int]]) -> int:
        if len(connections) < n - 1:
            return -1
        parent = [i for i in range(n)]
        def findParent(x):
            while parent[x] != x:
                parent[x] = parent[parent[x]]
                x = parent[x]
            return x
        count = n - 1
        for a, b in connections:
            pa = findParent(a)
            pb = findParent(b)
            if pa != pb:
                parent[pb] = pa
                count -= 1
        
        return count
