import math
class Solution:
    def nthUglyNumber(self, n: int, a: int, b: int, c: int) -> int:
        low = 1
        high = 2 * (10 ** 9)
        ab = a * b // math.gcd(a, b)
        bc = b * c // math.gcd(b, c)
        ac = a * c // math.gcd(a, c)
        abc = a * bc // math.gcd(a, bc)
        while low < high:
            mid = (low + high) // 2
            count = mid // a + mid // b + mid // c - mid // ab - mid // bc - mid // ac + mid // abc
            if count < n:
                low = mid + 1
            else:
                high = mid
        
        return low
