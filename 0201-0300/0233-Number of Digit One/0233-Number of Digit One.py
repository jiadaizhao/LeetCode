class Solution:
    def countDigitOne(self, n: int) -> int:
        base = 1
        count = 0
        while base <= n:
            curr = n // base % 10
            low = n % base
            high = n // (base * 10)
            if curr < 1:
                count += high * base
            elif curr == 1:
                count += high * base + low + 1
            else:
                count += (high + 1) * base
            base *= 10
        return count
