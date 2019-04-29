class Solution:
    def maxDistToClosest(self, seats: List[int]) -> int:
        maxDist = 0
        prev = -1
        for i, s in enumerate(seats):
            if s == 1:
                if prev == -1:
                    maxDist = i
                else:
                    maxDist = max(maxDist, (i - prev) // 2)
                prev = i
        if seats[-1] == 0:
            maxDist = max(maxDist, len(seats) - 1 - prev)
        return maxDist
