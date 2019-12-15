class Solution:
    def earliestAcq(self, logs: List[List[int]], N: int) -> int:
        parent = [i for i in range(N)]
        def findParent(x):
            while parent[x] != x:
                parent[x] = parent[parent[x]]
                x = parent[x]
            return x
        count = N
        for time, a, b in sorted(logs):
            pa = findParent(a)
            pb = findParent(b)
            if pa != pb:
                count -= 1
                if count == 1:
                    return time
                parent[pb] = pa
        return -1
