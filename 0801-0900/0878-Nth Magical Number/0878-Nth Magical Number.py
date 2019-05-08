import math
class Solution:
    def nthMagicalNumber(self, N: int, A: int, B: int) -> int:
        lcm = A * B // math.gcd(A, B)
        MOD = 10**9 + 7
        low = 2
        high = 10**14
        while low < high:
            mid = (low + high) // 2
            if mid // A + mid // B - mid // lcm < N:
                low = mid + 1
            else:
                high = mid
        return low % MOD
