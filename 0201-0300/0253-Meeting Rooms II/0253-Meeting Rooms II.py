class Solution:
    def minMeetingRooms(self, intervals: List[List[int]]) -> int:
        time = []
        for i in intervals:
            time.append((i[0], 1))
            time.append((i[1], 0))
        time.sort()
        count = maxCount = 0
        for t in time:
            if t[1] == 1:
                count += 1
                maxCount = max(maxCount, count)
            else:
                count -= 1
        return maxCount
