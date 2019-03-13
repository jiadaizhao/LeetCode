class MinStack:

    def __init__(self):
        """
        initialize your data structure here.
        """
        self.St = []

    def push(self, x: int) -> None:
        if not self.St:
            self.St.append(0)
            self.minVal = x
        else:
            self.St.append(x - self.minVal)
            if x < self.minVal:
                self.minVal = x

    def pop(self) -> None:
        diff = self.St.pop()
        if diff < 0:
            self.minVal -= diff

    def top(self) -> int:
        return self.St[-1] + self.minVal if self.St[-1] >= 0 else self.minVal

    def getMin(self) -> int:
        return self.minVal


# Your MinStack object will be instantiated and called as such:
# obj = MinStack()
# obj.push(x)
# obj.pop()
# param_3 = obj.top()
# param_4 = obj.getMin()
