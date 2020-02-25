class Vector2D:

    def __init__(self, v: List[List[int]]):
        def getIt():
            for row in v:
                for val in row:
                    yield val
                    
        self.it = iter(getIt())
        self.val = next(self.it, None)

    def next(self) -> int:
        result = self.val
        self.val = next(self.it, None)
        return result
        

    def hasNext(self) -> bool:
        return self.val is not None


# Your Vector2D object will be instantiated and called as such:
# obj = Vector2D(v)
# param_1 = obj.next()
# param_2 = obj.hasNext()
