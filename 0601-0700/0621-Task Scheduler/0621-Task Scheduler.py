import collections
class Solution:
    def leastInterval(self, tasks: List[str], n: int) -> int:
        table = collections.Counter(tasks)
        maxFreq = maxCount = 0
        for k, v in table.items():
            if v > maxFreq:
                maxFreq = v
                maxCount = 1
            elif v == maxFreq:
                maxCount += 1
        return max(len(tasks), (maxFreq - 1) * (n + 1) + maxCount)
