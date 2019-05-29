class Solution:
    def brokenCalc(self, X: int, Y: int) -> int:
        num = 0
        base = 1
        while X * base < Y:
            num += 1
            base <<= 1
        diff = X * base - Y
        while diff:
            num += diff // base
            diff %= base
            base >>= 1
        return num

class Solution2:
    def brokenCalc(self, X: int, Y: int) -> int:
        num = 0
        while X < Y:
            if Y & 1:
                Y += 1
            else:
                Y >>= 1
            num += 1

        return num + X - Y
