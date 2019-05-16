class Solution:
    def removeStones(self, stones: List[List[int]]) -> int:
        parent = {}
        island = 0
        def findParent(x):
            if x not in parent:
                parent[x] = x
                nonlocal island
                island += 1
            else:
                while parent[x] != x:
                    parent[x] = parent[parent[x]]
                    x = parent[x]
            return x
        for row, col in stones:
            pr = findParent(row)
            pc = findParent(~col)
            if pr != pc:
                parent[pr] = pc
                island -= 1
        return len(stones) - island
