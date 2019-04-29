import math
class Solution:
    def mirrorReflection(self, p: int, q: int) -> int:
        g = math.gcd(p, q)
        a = p // g
        if a & 1:
            return 1 if q//g&1 else 0
        else:
            return 2
