import collections
import bisect
import math
class TopVotedCandidate:

    def __init__(self, persons: List[int], times: List[int]):
        self.table = []
        maxCount = 0
        count = collections.Counter()
        for person, time in zip(persons, times):
            count[person] += 1
            if count[person] >= maxCount:
                maxCount = count[person]
                self.table.append((time, person))

    def q(self, t: int) -> int:
        index = bisect.bisect_right(self.table, (t, math.inf))
        return self.table[index - 1][1]


# Your TopVotedCandidate object will be instantiated and called as such:
# obj = TopVotedCandidate(persons, times)
# param_1 = obj.q(t)
