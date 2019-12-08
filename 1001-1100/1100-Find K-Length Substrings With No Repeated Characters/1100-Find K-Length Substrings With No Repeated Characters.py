import collections
class Solution:
    def numKLenSubstrNoRepeats(self, S: str, K: int) -> int:
        if K > 26 or K > len(S):
            return 0
        table = collections.Counter(S[:K])
        count = 1 if len(table) == K else 0
        for i in range(K, len(S)):
            table[S[i]] += 1
            table[S[i - K]] -= 1
            if table[S[i - K]] == 0:
                del table[S[i - K]]
            if len(table) == K:
                count += 1
        return count
