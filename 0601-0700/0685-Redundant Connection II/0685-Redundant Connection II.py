class Solution:
    def findRedundantDirectedConnection(self, edges: List[List[int]]) -> List[int]:
        parent = [i for i in range(len(edges) + 1)]
        def findParent(x):
            while parent[x] != x:
                parent[x] = parent[parent[x]]
                x = parent[x]
            return x
        
        visited = [-1] * (len(edges) + 1)
        first = second = last = -1
        for i, edge in enumerate(edges):
            n1 = edge[0]
            n2 = edge[1]
            if visited[n2] != -1:
                first = visited[n2]
                second = i
                continue
            visited[n2] = i
            
            p1 = findParent(n1)
            if p1 == n2:
                last = i
            else:
                parent[n2] = p1
                
        if last == -1:
            return edges[second]
        if second == -1:
            return edges[last]
        return edges[first]
