import math
class Solution:
    def simplifiedFractions(self, n: int) -> List[str]:
        result = []
        for d in range(2, n + 1):
            for n in range(1, d):
                if math.gcd(d, n) == 1:
                    result.append("{}/{}".format(n, d))
        return result
