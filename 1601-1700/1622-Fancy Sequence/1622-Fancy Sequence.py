class Fancy:

    def __init__(self):
        self.vals = []
        self.add = [0]
        self.mul = [1]

    def append(self, val: int) -> None:
        self.vals.append(val)
        self.add.append(self.add[-1])
        self.mul.append(self.mul[-1])

    def addAll(self, inc: int) -> None:
        self.add[-1] += inc

    def multAll(self, m: int) -> None:
        self.add[-1] = self.add[-1] * m % (10 ** 9 + 7)
        self.mul[-1] = self.mul[-1] * m % (10 ** 9 + 7)

    def getIndex(self, idx: int) -> int:
        if idx >= len(self.vals):
            return -1
        mod = 10 ** 9 + 7
        m = self.mul[-1] * pow(self.mul[idx], -1, mod) 
        inc = self.add[-1] - self.add[idx] * m
        return (self.vals[idx] * m + inc) % mod


# Your Fancy object will be instantiated and called as such:
# obj = Fancy()
# obj.append(val)
# obj.addAll(inc)
# obj.multAll(m)
# param_4 = obj.getIndex(idx)
