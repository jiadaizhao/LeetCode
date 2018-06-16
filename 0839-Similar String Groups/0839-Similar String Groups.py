class Solution:
    def numSimilarGroups(self, A):
        """
        :type A: List[str]
        :rtype: int
        """
        def isSimilar(s, t):
            return sum(ss != tt for ss, tt in zip(s, t)) == 2
        
        def findParent(parents, i):
            while parents[i] != i:
                parents[i] = parents[parents[i]]
                i = parents[i]
            return i
        
        n = len(A)
        parents = {x : x for x in A}
        count = n
        m = len(A[0])
        if n < m:
            for i, j in itertools.combinations(range(n), 2):
                if isSimilar(A[i], A[j]):
                    pa = findParent(parents, A[i])
                    pb = findParent(parents, A[j])
                    if pb != pa:
                        parents[pb] = pa
                        count -= 1
        else:
            for x in A:
                for i, j in itertools.combinations(range(m), 2):
                    y = x[:i] + x[j] + x[i + 1:j] + x[i] + x[j + 1:]
                    if y in parents:
                        pa = findParent(parents, x)
                        pb = findParent(parents, y)
                        if pb != pa:
                            parents[pb] = pa
                            count -= 1
        return count
