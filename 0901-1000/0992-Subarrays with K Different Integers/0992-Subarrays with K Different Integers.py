import collections
class Solution:
    def subarraysWithKDistinct(self, A: List[int], K: int) -> int:
        def atMostK(k):
            table = collections.Counter()
            num = count = start = 0
            for i, a in enumerate(A):
                table[a] += 1
                if table[a] == 1:
                    num += 1
                while num > k:
                    table[A[start]] -= 1
                    if table[A[start]] == 0:
                        num -= 1
                    start += 1
                count += i - start + 1
            return count
        
        return atMostK(K) - atMostK(K - 1)
