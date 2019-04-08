import re
import math
class Solution:
    def fractionAddition(self, expression: str) -> str:
        nums = map(int, re.findall(r'[+-]?\d+', expression))
        A, B = 0, 1
        for a in nums:
            b = next(nums)
            A = A * b + B * a
            B *= b
            g = math.gcd(A, B)
            A //= g
            B //= g
        return '{}/{}'.format(A, B)
