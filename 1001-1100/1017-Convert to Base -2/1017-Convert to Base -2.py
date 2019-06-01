class Solution:
    def baseNeg2(self, N: int) -> str:
        result = []
        while N:
            result.append(str(N & 1))
            N = -(N >> 1)
        return ''.join(result[::-1]) or '0'
