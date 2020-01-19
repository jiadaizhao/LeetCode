class Solution:
    def minFlips(self, a: int, b: int, c: int) -> int:
        count = 0
        while a or b:
            ba = a & 1
            bb = b & 1
            bc = c & 1
            if ba == 1 and bb == 1 and bc == 0:
                count += 2
            else:
                count += (ba | bb) ^ bc
            a >>= 1
            b >>= 1
            c >>= 1
        while c:
            count += (c & 1)
            c >>= 1
        return count


class Solution2:
    def minFlips(self, a: int, b: int, c: int) -> int:
        diff = (a | b) ^ c
        count = i = 0
        while diff:            
            if diff & 1:
                mask = 1 << i
                count += 2 if (a & mask) and (b & mask) and (c & mask) == 0 else 1
            diff >>= 1
            i += 1
        return count
