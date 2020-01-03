class MaxStack:

    def __init__(self):
        """
        initialize your data structure here.
        """
        self.St = []
        self.maxSt = []

    def push(self, x: int) -> None:
        self.St.append(x)
        maxX = x if not self.maxSt or x > self.maxSt[-1] else self.maxSt[-1]
        self.maxSt.append(maxX)

    def pop(self) -> int:
        self.maxSt.pop()
        return self.St.pop()

    def top(self) -> int:
        return self.St[-1]

    def peekMax(self) -> int:
        return self.maxSt[-1]

    def popMax(self) -> int:
        maxX = self.maxSt[-1]
        buffer = []
        while self.St[-1] != maxX:
            buffer.append(self.pop())
        self.pop()
        while buffer:
            self.push(buffer.pop())
        return maxX


# Your MaxStack object will be instantiated and called as such:
# obj = MaxStack()
# obj.push(x)
# param_2 = obj.pop()
# param_3 = obj.top()
# param_4 = obj.peekMax()
# param_5 = obj.popMax()
