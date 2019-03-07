class Solution:
    def myPow(self, x: float, n: int) -> float:
        result = 1
        if n < 0:
            x = 1/x
            n = -n
        while n:
            if n & 1:
                result *= x
            x *= x
            n >>= 1
        return result
