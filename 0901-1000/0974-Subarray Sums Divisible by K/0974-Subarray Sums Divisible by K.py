import collections
class Solution:
    def subarraysDivByK(self, A: List[int], K: int) -> int:
        table = collections.Counter([0])
        sum = count = 0
        for a in A:
            sum = (sum + a) % K
            count += table[sum]
            table[sum] += 1
        return count

class Solution2:
    def subarraysDivByK(self, A: List[int], K: int) -> int:
        table = [1] + [0] * K
        sum = count = 0
        for a in A:
            sum = (sum + a) % K
            count += table[sum]
            table[sum] += 1
        return count
