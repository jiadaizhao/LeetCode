import math
class Solution:
    def findCriticalAndPseudoCriticalEdges(self, n: int, edges: List[List[int]]) -> List[List[int]]:
        for i in range(len(edges)):
            edges[i].append(i)
        edges.sort(key=lambda e: e[2])
        def findParent(parent, x):
            while parent[x] != x:
                parent[x] = parent[parent[x]]
                x = parent[x]
            return x

        def getMST(block, prev):
            parent = [i for i in range(n)]
            weight = count = 0
            if prev != -1:
                a, b, w, _ = edges[prev]
                parent[b] = a
                count = 1
                weight = w
            for i in range(len(edges)):
                if i == block or i == prev:
                    continue
                a, b, w, _ = edges[i]
                pa = findParent(parent, a)
                pb = findParent(parent, b)
                if pa != pb:
                    parent[pb] = pa
                    count += 1
                    weight += w
                    if count == n - 1:
                        break
                        
            return weight if count == n - 1 else math.inf
        
        original = getMST(-1, -1)
        critical = []
        pseudoCritical = []
        for i in range(len(edges)):
            if getMST(i, -1) > original:
                critical.append(edges[i][3])
            elif getMST(-1, i) == original:
                pseudoCritical.append(edges[i][3])
        return [critical, pseudoCritical]
