class Solution:
    def bitwiseComplement(self, N: int) -> int:
        limit = 2
        while N >= limit:
            limit <<= 1
        return limit - 1 - N
