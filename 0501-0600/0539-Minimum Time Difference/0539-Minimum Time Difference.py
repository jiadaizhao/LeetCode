class Solution:
    def findMinDifference(self, timePoints: List[str]) -> int:
        bucket = [0] * 1440
        for time in timePoints:
            index = int(time[:2]) * 60 + int(time[3:])
            bucket[index] += 1
            if bucket[index] > 1:
                return 0
        first = last = -1
        minDiff = 1440
        for i, b in enumerate(bucket):
            if b:
                if first == -1:
                    first = i
                else:
                    minDiff = min(minDiff, i - last)
                last = i
        return min(minDiff, 1440 - (last - first))
