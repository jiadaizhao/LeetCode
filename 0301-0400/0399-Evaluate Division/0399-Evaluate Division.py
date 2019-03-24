class Solution:
    def calcEquation(self, equations: List[List[str]], values: List[float], queries: List[List[str]]) -> List[float]:
        table = {}
        parents = {}
        def findParent(s):
            while parents[s] != s:
                parents[s] = parents[parents[s]]
                s = parents[s]
            return s

        for eq, val in zip(equations, values):
            s1, s2 = eq
            if s1 not in table:
                table[s1] = val
                parents[s1] = s1
            if s2 not in table:
                table[s2] = 1
                parents[s2] = s2
            
            p1 = findParent(s1)
            p2 = findParent(s2)
            if p1 != p2:
                ratio = table[s2] * val / table[s1]
                for s in table:
                    if findParent(s) == p1:
                        table[s] *= ratio
                parents[p2] = p1
                
        result = [-1] * len(queries)
        for i, (s1, s2) in enumerate(queries):
            if s1 in table and s2 in table and findParent(s1) == findParent(s2):
                result[i] = table[s1] / table[s2]
                
        return result
