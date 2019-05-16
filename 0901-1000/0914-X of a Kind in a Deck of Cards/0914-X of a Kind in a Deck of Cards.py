import collections
import math
import functools
class Solution:
    def hasGroupsSizeX(self, deck: List[int]) -> bool:
        table = collections.Counter(deck)
        return functools.reduce(math.gcd, table.values()) >= 2
