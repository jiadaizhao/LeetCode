# Definition for an Interval.
class Interval:
    def __init__(self, start: int = None, end: int = None):
        self.start = start
        self.end = end

class Solution:
    def employeeFreeTime(self, schedule: '[[Interval]]') -> '[Interval]':
        intervals = sorted([i for s in schedule for i in s], key=lambda i: i.start)
        prevEnd = intervals[0].end
        result = []
        for i in intervals[1:]:
            if i.start > prevEnd:
                result.append(Interval(prevEnd, i.start))
            prevEnd = max(prevEnd, i.end)
        return result
