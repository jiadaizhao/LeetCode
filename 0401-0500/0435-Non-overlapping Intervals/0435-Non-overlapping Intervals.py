import math
class Solution:
    def eraseOverlapIntervals(self, intervals: List[List[int]]) -> int:
        intervals.sort()
        count = 0
        prev = -math.inf
        for interval in intervals:
            if interval[0] < prev:
                count += 1
                prev = min(prev, interval[1])
            else:
                prev = interval[1]
        return count
