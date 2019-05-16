import collections
import itertools
class Solution:
    def threeSumMulti(self, A: List[int], target: int) -> int:
        table = collections.Counter(A)
        MOD = 10 ** 9 + 7
        total = 0
        for Ai, Aj in itertools.combinations_with_replacement(sorted(table), 2):
            Ak = target - Ai - Aj
            if Ak not in table:
                continue
            if Ai == Aj:
                if Aj == Ak:
                    total = (total + table[Ai] * (table[Ai] - 1) * (table[Ai] - 2) // 6) % MOD
                else:
                    total = (total + table[Ai] * (table[Ai] - 1) // 2 * table[Ak]) % MOD
            elif Ai < Aj < Ak:
                total = (total + table[Ai] * table[Aj] * table[Ak]) % MOD
        return total
