class Solution:
    def largestComponentSize(self, A: List[int]) -> int:
        parent = list(range(len(A)))
        def findParent(x):
            while parent[x] != x:
                parent[x] = parent[parent[x]]
                x = parent[x]
                
            return x
        table = {}
        area = [1] * len(A)
        def merge(d, i):
            if d not in table:
                table[d] = i
            else:
                p1 = findParent(table[d])
                p2 = findParent(i)
                if p1 != p2:
                    if area[p1] < area[p2]:
                        parent[p1] = p2
                        area[p2] += area[p1]
                    else:
                        parent[p2] = p1
                        area[p1] += area[p2]

        for i, a in enumerate(A):
            d = 2
            while d * d <= a:
                if a % d == 0:
                    while a % d == 0:
                        a //= d
                    merge(d, i)
                d += 1
                
            if a > 1:
                merge(a, i)
        
        return max(area)
