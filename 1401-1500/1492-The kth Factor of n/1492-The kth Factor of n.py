class Solution:
    def kthFactor(self, n: int, k: int) -> int:
        d = 1
        while d * d <= n:
            if n % d == 0:
                k -= 1
                if k == 0:
                    return d
            d += 1
        d -= 1
        while d >= 1:
            if d * d == n:
                d -= 1
                continue
            if n % d == 0:
                k -= 1
                if k == 0:
                    return n // d
            d -= 1
        return -1
