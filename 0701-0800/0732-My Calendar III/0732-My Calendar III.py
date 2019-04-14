import collections
class MyCalendarThree:

    def __init__(self):
        self.table = collections.Counter()

    def book(self, start: int, end: int) -> int:
        self.table[start] += 1
        self.table[end] -= 1
        curr = maxCount = 0
        for k in sorted(self.table):
            curr += self.table[k]
            maxCount = max(maxCount, curr)
        return maxCount


# Your MyCalendarThree object will be instantiated and called as such:
# obj = MyCalendarThree()
# param_1 = obj.book(start,end)
