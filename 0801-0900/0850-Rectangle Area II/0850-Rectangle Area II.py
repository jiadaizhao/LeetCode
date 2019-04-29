class Node:
    def __init__(self, start, end):
        self.start = start
        self.end = end
        self.left = self.right = None
        self.count = self.total = 0
        
    def getLeft(self):
        if self.left is None:
            self.left = Node(self.start, (self.start + self.end)//2)
        return self.left
    
    def getRight(self):
        if self.right is None:
            self.right = Node((self.start + self.end)//2, self.end)
        return self.right
        
    def update(self, i, j, val, X):
        if i >= j:
            return 0
        if self.start == i and self.end == j:
            self.count += val
        else:
            mid = (self.start + self.end)//2
            self.getLeft().update(i, min(mid, j), val, X)
            self.getRight().update(max(mid, i), j, val, X)
            
        if self.count > 0:
            self.total = X[self.end] - X[self.start]
        else:
            self.total = self.getLeft().total + self.getRight().total
        return self.total
            
class Solution:
    def rectangleArea(self, rectangles: List[List[int]]) -> int:
        MOD = 10**9 + 7
        xs = set()
        events = []
        for x1, y1, x2, y2 in rectangles:
            xs.add(x1)
            xs.add(x2)
            events.append((y1, 1, x1, x2))
            events.append((y2, -1, x1, x2))
        events.sort()
        X = sorted(xs)
        table = {x: i for i, x in enumerate(X)}
        root = Node(0, len(X) - 1)
        area = currY = currXSum = 0
        for y, typ, x1, x2 in events:
            area = (area + currXSum * (y - currY)) % MOD
            currXSum = root.update(table[x1], table[x2], typ, X)
            currY = y
        return area
