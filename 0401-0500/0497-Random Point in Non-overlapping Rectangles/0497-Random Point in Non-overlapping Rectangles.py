import bisect
import random
import itertools
class Solution:

    def __init__(self, rects: List[List[int]]):
        self.rects = rects
        self.presum = list(itertools.accumulate((rect[2] - rect[0] + 1) * (rect[3] - rect[1] + 1) for rect in rects))

    def pick(self) -> List[int]:
        target = random.randint(1, self.presum[-1])
        index = bisect.bisect_left(self.presum, target)
        x1, y1, x2, y2 = self.rects[index]
        width = x2 - x1 + 1
        return [x1 + (self.presum[index] - target) % width, y1 + (self.presum[index] - target) // width]


# Your Solution object will be instantiated and called as such:
# obj = Solution(rects)
# param_1 = obj.pick()
