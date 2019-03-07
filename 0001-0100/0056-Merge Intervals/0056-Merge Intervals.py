# Definition for an interval.
# class Interval:
#     def __init__(self, s=0, e=0):
#         self.start = s
#         self.end = e

class Solution:
    def merge(self, intervals: List[Interval]) -> List[Interval]:
        intervals.sort(key= lambda x: (x.start, x.end))
        result = []
        for interval in intervals:
            if result and interval.start <= result[-1].end:
                result[-1].end = max(result[-1].end, interval.end)
            else:
                result.append(interval)
        return result
