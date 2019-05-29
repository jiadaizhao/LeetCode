import collections
class Solution:
    def countTriplets(self, A) -> int:
        total = 0
        table = collections.Counter()
        for a in A:
            for b in A:
                table[a & b] += 1

        for a in A:
            for i in table:
                if a & i == 0:
                    total += table[i]

        return total

class Solution2:
    def countTriplets(self, A: List[int]) -> int:
        total = 0
        table = [0] * (1 << 16)
        for a in A:
            for b in A:
                table[a & b] += 1

        for a in A:
            i = 0
            while i < (1 << 16):
                if a & i == 0:
                    total += table[i]
                    i += 1
                else:
                    i += a & i

        return total
