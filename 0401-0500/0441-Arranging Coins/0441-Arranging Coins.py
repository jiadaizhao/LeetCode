import math
class Solution:
    def arrangeCoins(self, n: int) -> int:
        return int(math.sqrt(1 + 8*n) - 1) // 2
