import collections
class Solution:
    def countPairs(self, deliciousness: List[int]) -> int:
        MOD = 10 ** 9 + 7
        table = collections.Counter()
        result = 0
        for num in deliciousness:
            for i in range(22):
                power = 1 << i
                if power - num in table:
                    result = (result + table[power - num]) % MOD
            table[num] += 1
        return result
