import math
class Solution:
    def smallestGoodBase(self, n: str) -> str:
        num = int(n)
        maxm = int(math.log(num, 2))
        for m in range(maxm, 1, -1):
            k = int(num ** m ** (-1))
            if k ** (m + 1) == num * k - num + 1:
                return str(k)
        return str(num - 1)
