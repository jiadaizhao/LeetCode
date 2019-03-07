class Solution:
    def divide(self, dividend: int, divisor: int) -> int:
        if dividend == 0:
            return 0
        sign = 1
        if (dividend > 0 and divisor < 0) or (dividend < 0 and divisor > 0):
            sign = -1
        a = abs(dividend)
        b = abs(divisor)
        result = 0
        while a >= b:
            shift = 0
            while (b << shift) <= a:
                shift += 1
            result += (1 << (shift - 1))
            a -= (b << (shift - 1))
        result *= sign
        return min(result, (1 << 31) - 1)  
