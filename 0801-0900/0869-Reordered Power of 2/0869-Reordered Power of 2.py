class Solution:
    def reorderedPowerOf2(self, N: int) -> bool:
        def countDigits(N):
            result = 0
            while N:
                result += 10 ** (N % 10)
                N //= 10
            return result
        result = countDigits(N)
        return any(result == countDigits(1 << i) for i in range(31))


import collections
class Solution2:
    def reorderedPowerOf2(self, N: int) -> bool:
        curr = collections.Counter(str(N))
        return any(curr == collections.Counter(str(1 << i)) for i in range(31))
