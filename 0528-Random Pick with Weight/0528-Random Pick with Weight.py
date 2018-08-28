import itertools
import random
import bisect
class Solution:

    def __init__(self, w):
        """
        :type w: List[int]
        """
        self.presum = list(itertools.accumulate(w))

    def pickIndex(self):
        """
        :rtype: int
        """
        return bisect.bisect_left(self.presum, random.randint(1, self.presum[-1]))
        


# Your Solution object will be instantiated and called as such:
# obj = Solution(w)
# param_1 = obj.pickIndex()