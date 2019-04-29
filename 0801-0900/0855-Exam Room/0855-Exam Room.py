import bisect
class ExamRoom:

    def __init__(self, N: int):
        self.N = N
        self.seats = []

    def seat(self) -> int:
        res = 0
        if self.seats:
            maxGap = self.seats[0]
            prev = 0
            for curr in self.seats:
                gap = (curr - prev) // 2
                if gap > maxGap:
                    maxGap = gap
                    res = prev + gap
                prev = curr
            if self.N - 1 - self.seats[-1] > maxGap:
                res = self.N - 1
        bisect.insort(self.seats, res)
        return res

    def leave(self, p: int) -> None:
        self.seats.remove(p)


# Your ExamRoom object will be instantiated and called as such:
# obj = ExamRoom(N)
# param_1 = obj.seat()
# obj.leave(p)
