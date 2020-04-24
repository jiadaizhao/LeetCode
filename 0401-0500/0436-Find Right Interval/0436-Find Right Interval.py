import bisect
class Solution:
    def findRightInterval(self, intervals: List[List[int]]) -> List[int]:
        table = sorted((interval[0], i) for i, interval in enumerate(intervals))
        result = [-1] * len(intervals)

        for i in range(len(intervals)):
            index = bisect.bisect_left(table, (intervals[i][1],))
            if index < len(intervals):
                result[i] = table[index][1]
        return result
