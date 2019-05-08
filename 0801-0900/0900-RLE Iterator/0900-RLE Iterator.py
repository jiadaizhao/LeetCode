class RLEIterator:
    
    def __init__(self, A: List[int]):
        self.A = A
        self.start = 0
        self.num = 0

    def next(self, n: int) -> int:
        while self.start < len(self.A):
            if self.num + n <= self.A[self.start]:
                self.num += n
                return self.A[self.start + 1]
            else:
                n -= self.A[self.start] - self.num
                self.num = 0
                self.start += 2
        return -1


# Your RLEIterator object will be instantiated and called as such:
# obj = RLEIterator(A)
# param_1 = obj.next(n)
