class Solution:
    def removeCoveredIntervals(self, intervals: List[List[int]]) -> int:
        intervals.sort(key=lambda x: (x[0], -x[1]))
        count = 0
        end = -1
        for a, b in intervals:
            if b > end:
                count += 1
                end = b
        return count
