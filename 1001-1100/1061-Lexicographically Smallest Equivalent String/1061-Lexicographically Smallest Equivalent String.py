import string
class Solution:
    def smallestEquivalentString(self, A: str, B: str, S: str) -> str:
        parent = {c: c for c in string.ascii_lowercase}
        def findParent(x):
            while parent[x] != x:
                parent[x] = parent[parent[x]]
                x = parent[x]
            return x
        
        for c1, c2 in zip(A, B):
            p1 = findParent(c1)
            p2 = findParent(c2)
            if p1 < p2:
                parent[p2] = p1
            elif p1 > p2:
                parent[p1] = p2
                
        return ''.join(findParent(c) for c in S)
