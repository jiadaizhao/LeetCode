class MyCalendar:

    def __init__(self):
        self.time = []

    def book(self, start: int, end: int) -> bool:
        for s, e in self.time:
            if s < end and e > start:
                return False
        self.time.append((start, end))
        return True


# Your MyCalendar object will be instantiated and called as such:
# obj = MyCalendar()
# param_1 = obj.book(start,end)
