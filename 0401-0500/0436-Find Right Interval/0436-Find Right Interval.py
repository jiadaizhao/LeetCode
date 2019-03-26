# Definition for an interval.
class Interval:
    def __init__(self, s=0, e=0):
        self.start = s
        self.end = e

import bisect
class Solution:
    def findRightInterval(self, intervals: List[Interval]) -> List[int]:
        table = sorted((interval.start, i) for i, interval in enumerate(intervals))
        result = [-1] * len(intervals)

        for i in range(len(intervals)):
            index = bisect.bisect_left(table, (intervals[i].end,))
            if index < len(intervals):
                result[i] = table[index][1]
        return result
