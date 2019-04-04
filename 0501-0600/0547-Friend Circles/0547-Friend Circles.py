class Solution:
    def findCircleNum(self, M: List[List[int]]) -> int:
        parent = [i for i in range(len(M))]
        def findParent(i):
            while parent[i] != i:
                parent[i] = parent[parent[i]]
                i = parent[i]
            return i
        
        count = len(M)
        for i in range(len(M)):
            for j in range(i + 1, len(M[i])):
                if M[i][j] == 1:
                    pi = findParent(i)
                    pj = findParent(j)
                    if pi != pj:
                        count -= 1
                        parent[pi] = pj
        return count
