import collections
class Solution:
    def numOfSubarrays(self, arr: List[int]) -> int:
        MOD = 10 ** 9 + 7
        table = collections.Counter([0])
        presum = total = 0
        for num in arr:
            presum = (presum + num) & 1
            total = (total + table[1 - presum]) % MOD
            table[presum] += 1
        return total
