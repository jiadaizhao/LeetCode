# Definition for an interval.
# class Interval:
#     def __init__(self, s=0, e=0):
#         self.start = s
#         self.end = e

class Solution:
    def insert(self, intervals: List[Interval], newInterval: Interval) -> List[Interval]:
        result = []
        i = 0
        while i < len(intervals):
            if intervals[i].end < newInterval.start:
                result.append(intervals[i])
            elif intervals[i].start > newInterval.end:
                break
            else:
                newInterval.start = min(newInterval.start, intervals[i].start)
                newInterval.end = max(newInterval.end, intervals[i].end)
            i += 1
        result.append(newInterval)
        result += intervals[i:]
        return result
