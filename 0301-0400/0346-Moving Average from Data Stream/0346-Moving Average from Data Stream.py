import collections
class MovingAverage:

    def __init__(self, size: int):
        """
        Initialize your data structure here.
        """
        self.Q = collections.deque()
        self.capacity = size
        self.sum = 0

    def next(self, val: int) -> float:
        self.sum += val
        if len(self.Q) == self.capacity:
            self.sum -= self.Q.popleft()
        self.Q.append(val)
        return self.sum / len(self.Q)


# Your MovingAverage object will be instantiated and called as such:
# obj = MovingAverage(size)
# param_1 = obj.next(val)
