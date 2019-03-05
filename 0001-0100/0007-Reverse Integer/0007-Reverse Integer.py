class Solution:
    def reverse(self, x: int) -> int:
        result = 0
        sign = 1 if x >= 0 else -1
        x = x*sign
        while x:
            result = result*10 + x%10
            x //= 10
        result *= sign
        INT_MIN = -(1 << 31)
        INT_MAX = (1 << 31) - 1
        return 0 if result < INT_MIN or result > INT_MAX else result
