class Solution:
    def equationsPossible(self, equations: List[str]) -> bool:
        parent = {}
        def findParent(x):
            if x not in parent:
                parent[x] = x
            else:
                while parent[x] != x:
                    parent[x] = parent[parent[x]]
                    x = parent[x]
            return x

        for eq in equations:
            if eq[1] == '=':
                x, y = eq[0], eq[3]
                px = findParent(x)
                py = findParent(y)
                parent[px] = py
                
        for eq in equations:
            if eq[1] == '!':
                x, y = eq[0], eq[3]
                px = findParent(x)
                py = findParent(y)
                if px == py:
                    return False
        return True
