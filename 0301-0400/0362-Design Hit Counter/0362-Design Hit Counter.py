import collections
class HitCounter:

    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.Q = collections.deque()


    def hit(self, timestamp: int) -> None:
        """
        Record a hit.
        @param timestamp - The current timestamp (in seconds granularity).
        """
        while self.Q and self.Q[0] <= timestamp - 300:
            self.Q.popleft()
        self.Q.append(timestamp)
        

    def getHits(self, timestamp: int) -> int:
        """
        Return the number of hits in the past 5 minutes.
        @param timestamp - The current timestamp (in seconds granularity).
        """
        while self.Q and self.Q[0] <= timestamp - 300:
            self.Q.popleft()
        return len(self.Q)


# Your HitCounter object will be instantiated and called as such:
# obj = HitCounter()
# obj.hit(timestamp)
# param_2 = obj.getHits(timestamp)
