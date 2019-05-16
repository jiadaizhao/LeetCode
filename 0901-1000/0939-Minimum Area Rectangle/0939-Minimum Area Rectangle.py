import collections
class Solution:
    def minAreaRect(self, points: List[List[int]]) -> int:
        table = collections.defaultdict(set)
        for x, y in points:
            table[x].add(y)
            
        minArea = 0
        for j, p2 in enumerate(points):
            for i in range(j):
                p1 = points[i]
                if p1[0] == p2[0] or p1[1] == p2[1]:
                    continue
                if p2[1] in table[p1[0]] and p1[1] in table[p2[0]]:
                    area = abs((p2[0] - p1[0])*(p2[1] - p1[1]))
                    if minArea == 0 or area < minArea:
                        minArea = area
        return minArea

class Solution2:
    def minAreaRect(self, points: List[List[int]]) -> int:
        n = len(points)
        nx = len(set(x for x, y in points))
        ny = len(set(y for x, y in points))
        if nx == n or ny == n:
            return 0

        table = collections.defaultdict(list)
        if nx > ny:
            for x, y in points:
                table[x].append(y)
        else:
            for x, y in points:
                table[y].append(x)

        lastx = {}
        minArea = 0
        for x in sorted(table):
            table[x].sort()
            for i in range(len(table[x])):
                for j in range(i):
                    y1, y2 = table[x][j], table[x][i]
                    if (y1, y2) in lastx:
                        area = (x - lastx[y1, y2]) * (y2 - y1)
                        if minArea == 0 or area < minArea:
                            minArea = area
                    lastx[y1, y2] = x
        return minArea
