import collections
class Solution:
    def minimumHammingDistance(self, source: List[int], target: List[int], allowedSwaps: List[List[int]]) -> int:
        n = len(source)
        parent = list(range(n))
        def findParent(x):
            while parent[x] != x:
                parent[x] = parent[parent[x]]
                x = parent[x]
            return x
        
        for a, b in allowedSwaps:
            pa = findParent(a)
            pb = findParent(b)
            if pa != pb:
                parent[pb] = pa
        
        table = collections.defaultdict(collections.Counter)
        for i, num in enumerate(source):
            p = findParent(i)
            table[p][num] += 1
            
        dist = 0
        for i, num in enumerate(target):
            p = findParent(i)
            if table[p][num] > 0:
                table[p][num] -= 1
            else:
                dist += 1
        return dist
