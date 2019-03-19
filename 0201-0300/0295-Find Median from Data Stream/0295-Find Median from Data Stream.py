import heapq
class MedianFinder:

    def __init__(self):
        """
        initialize your data structure here.
        """
        self.maxpq = []
        self.minpq = []

    def addNum(self, num: int) -> None:
        heapq.heappush(self.maxpq, -num)
        heapq.heappush(self.minpq, -heapq.heappop(self.maxpq))
        if len(self.maxpq) < len(self.minpq):
            heapq.heappush(self.maxpq, -heapq.heappop(self.minpq))

    def findMedian(self) -> float:
        return (-self.maxpq[0] + self.minpq[0]) / 2 if len(self.maxpq) == len(self.minpq) else -self.maxpq[0]


# Your MedianFinder object will be instantiated and called as such:
# obj = MedianFinder()
# obj.addNum(num)
# param_2 = obj.findMedian()
