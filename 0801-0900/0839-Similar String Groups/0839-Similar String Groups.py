class Solution:
    def numSimilarGroups(self, A: List[str]) -> int:
        m, n = len(A), len(A[0])
        def isSimilar(X, Y):
            diff = 0
            for x, y in zip(X, Y):
                if x != y:
                    diff += 1
                    if diff > 2:
                        return False
            return True
        
        def findParent(i):
            while parent[i] != i:
                parent[i] = parent[parent[i]]
                i = parent[i]
            return i
        
        if m < n:
            count = m
            parent = [i for i in range(m)]
            for i in range(m):
                for j in range(i):
                    if isSimilar(A[i], A[j]):
                        pa = findParent(i)
                        pb = findParent(j)
                        if pa != pb:
                            parent[pb] = pa
                            count -= 1
        else:
            A = set(A)
            count = len(A)
            parent = {x: x for x in A}
            for x in A:
                for j in range(n):
                    for i in range(j):
                        y = x[:i] + x[j] + x[i+1:j] + x[i] + x[j+1:]
                        if y in parent:
                            pa = findParent(x)
                            pb = findParent(y)
                            if pa != pb:
                                parent[pb] = pa
                                count -= 1
        return count
