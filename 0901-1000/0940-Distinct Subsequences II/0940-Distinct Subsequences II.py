import collections
class Solution:
    def distinctSubseqII(self, S: str) -> int:
        total, end = 0, collections.Counter()
        MOD = 10 ** 9 + 7
        for c in S:
            total, end[c] = (total * 2 + 1 - end[c]) % MOD, (total + 1) % MOD
        return total
