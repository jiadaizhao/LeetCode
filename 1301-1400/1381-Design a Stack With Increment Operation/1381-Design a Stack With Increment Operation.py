class CustomStack:

    def __init__(self, maxSize: int):
        self.St = []
        self.maxSize = maxSize

    def push(self, x: int) -> None:
        if len(self.St) < self.maxSize:
            self.St.append([x, 0])

    def pop(self) -> int:
        if not self.St:
            return -1
        num, inc = self.St[-1]
        self.St.pop()
        if self.St:
            self.St[-1][1] += inc
        return num + inc

    def increment(self, k: int, val: int) -> None:
        if self.St:
            self.St[min(len(self.St), k) - 1][1] += val


# Your CustomStack object will be instantiated and called as such:
# obj = CustomStack(maxSize)
# obj.push(x)
# param_2 = obj.pop()
# obj.increment(k,val)
