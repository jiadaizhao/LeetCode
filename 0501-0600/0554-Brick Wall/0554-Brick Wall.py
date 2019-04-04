import collections
class Solution:
    def leastBricks(self, wall: List[List[int]]) -> int:
        table = collections.Counter()
        maxCount = 0
        for row in wall:
            presum = 0
            for val in row[:-1]:
                presum += val
                table[presum] += 1
                if table[presum] > maxCount:
                    maxCount = table[presum]
        return len(wall) - maxCount
