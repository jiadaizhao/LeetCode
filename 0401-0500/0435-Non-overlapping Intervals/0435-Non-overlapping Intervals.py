# Definition for an interval.
class Interval:
   def __init__(self, s=0, e=0):
        self.start = s
        self.end = e

import math
class Solution:
    def eraseOverlapIntervals(self, intervals: 'List[Interval]') -> 'int':
        intervals.sort(key=lambda x: x.start)
        count = 0
        prev = -math.inf
        for interval in intervals:
            if interval.start < prev:
                count += 1
                prev = min(prev, interval.end)
            else:
                prev = interval.end
        return count
