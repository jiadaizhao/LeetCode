import collections
import bisect
class TweetCounts:

    def __init__(self):
        self.table = collections.defaultdict(list)


    def recordTweet(self, tweetName: str, time: int) -> None:
        bisect.insort(self.table[tweetName], time)
        

    def getTweetCountsPerFrequency(self, freq: str, tweetName: str, startTime: int, endTime: int) -> List[int]:
        if freq == 'minute':
            delta = 60
        elif freq == 'hour':
            delta = 3600
        else:
            delta = 86400
        result = []
        t = startTime
        while t <= endTime:
            end = min(t + delta, endTime + 1)
            result.append(bisect.bisect_left(self.table[tweetName], end) - bisect.bisect_left(self.table[tweetName], t))
            t += delta
        return result


# Your TweetCounts object will be instantiated and called as such:
# obj = TweetCounts()
# obj.recordTweet(tweetName,time)
# param_2 = obj.getTweetCountsPerFrequency(freq,tweetName,startTime,endTime)
