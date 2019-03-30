class Solution:
    def findPoisonedDuration(self, timeSeries: List[int], duration: int) -> int:
        if not timeSeries:
            return 0
        total = duration
        for i in range(1, len(timeSeries)):
            total += min(duration, timeSeries[i] - timeSeries[i - 1])
        return total
