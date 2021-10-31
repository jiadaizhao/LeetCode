class OrderedStream:

    def __init__(self, n: int):
        self.ptr = 0
        self.val = [None] * n

    def insert(self, idKey: int, value: str) -> List[str]:
        result = []
        self.val[idKey - 1] = value
        while self.ptr < len(self.val) and self.val[self.ptr]:
            result.append(self.val[self.ptr])
            self.ptr += 1
        return result


# Your OrderedStream object will be instantiated and called as such:
# obj = OrderedStream(n)
# param_1 = obj.insert(idKey,value)
