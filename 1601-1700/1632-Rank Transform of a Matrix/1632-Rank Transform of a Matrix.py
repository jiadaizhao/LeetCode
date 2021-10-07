import collections
class Solution:
    def matrixRankTransform(self, matrix: List[List[int]]) -> List[List[int]]:
        m, n = len(matrix), len(matrix[0])
        table = collections.defaultdict(list)
        for i in range(m):
            for j in range(n):
                table[matrix[i][j]].append((i, j))
                
        def findParent(x):
            while parent[x] != x:
                parent[x] = parent[parent[x]]
                x = parent[x]
            return x
        
        rank = [0] * (m + n)
        result = [[0] * n for _ in range(m)]
        for val in sorted(table):
            parent = {}
            for r, c in table[val]:
                parent.setdefault(r, r)
                parent.setdefault(c + m, c + m)
                pr = findParent(r)
                pc = findParent(c + m)
                if pr != pc:
                    parent[pc] = pr
                    
            groups = collections.defaultdict(list)
            for i in parent.keys():
                groups[findParent(i)].append(i)
            for group in groups.values():
                maxRank = max(rank[i] for i in group)
                for i in group:
                    rank[i] = maxRank + 1
            for r, c in table[val]:
                result[r][c] = rank[r]
        return result
