import collections
class FrontMiddleBackQueue:

    def __init__(self):
        self.dq1 = collections.deque()
        self.dq2 = collections.deque()

    def pushFront(self, val: int) -> None:
        self.dq1.appendleft(val)
        if len(self.dq1) > len(self.dq2) + 1:
            self.dq2.appendleft(self.dq1.pop())

    def pushMiddle(self, val: int) -> None:
        if len(self.dq1) > len(self.dq2):
            self.dq2.appendleft(self.dq1.pop())
        self.dq1.append(val)       

    def pushBack(self, val: int) -> None:
        self.dq2.append(val)
        if len(self.dq1) < len(self.dq2):
            self.dq1.append(self.dq2.popleft())

    def popFront(self) -> int:
        if self.dq1:
            val = self.dq1.popleft()
            if len(self.dq1) < len(self.dq2):
                self.dq1.append(self.dq2.popleft())
            return val
        else:
            return -1

    def popMiddle(self) -> int:
        if self.dq1:
            val = self.dq1.pop()
            if len(self.dq1) < len(self.dq2):
                self.dq1.append(self.dq2.popleft())
            return val
        else:
            return -1

    def popBack(self) -> int:
        if self.dq2:
            val = self.dq2.pop()
            if len(self.dq1) > len(self.dq2) + 1:
                self.dq2.appendleft(self.dq1.pop())
            return val
        elif self.dq1:
            return self.dq1.pop()
        else:
            return -1
            


# Your FrontMiddleBackQueue object will be instantiated and called as such:
# obj = FrontMiddleBackQueue()
# obj.pushFront(val)
# obj.pushMiddle(val)
# obj.pushBack(val)
# param_4 = obj.popFront()
# param_5 = obj.popMiddle()
# param_6 = obj.popBack()
