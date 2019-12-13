class Solution:
    def digitsCount(self, d: int, low: int, high: int) -> int:
        def countDigit(d, n):
            if d == 0 and n == 0:
                return 1
            base = 1
            count = 0
            while base <= n:
                curr = n // base % 10
                low = n % base
                high = n // (base * 10)
                if d != 0:
                    if curr < d:
                        count += high * base
                    elif curr == d:
                        count += high * base + low + 1
                    else:
                        count += (high + 1) * base
                else:
                    if base == 1:
                        count += high + 1
                    elif high != 0:
                        if curr > 0:
                            count += high * base
                        else:
                            count += (high - 1) * base + low + 1

                base *= 10

            return count
            
        return countDigit(d, high) - countDigit(d, low - 1)
