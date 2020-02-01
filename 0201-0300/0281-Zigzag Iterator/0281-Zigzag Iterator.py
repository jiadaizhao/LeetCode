import itertools
class ZigzagIterator:
    def __init__(self, v1: List[int], v2: List[int]):
        self.vals = (v[i] for i in itertools.count() for v in (v1, v2) if i < len(v))
        self.n = len(v1) + len(v2)


    def next(self) -> int:
        self.n -= 1
        return next(self.vals)
        

    def hasNext(self) -> bool:
        return self.n > 0
        

# Your ZigzagIterator object will be instantiated and called as such:
# i, v = ZigzagIterator(v1, v2), []
# while i.hasNext(): v.append(i.next())
