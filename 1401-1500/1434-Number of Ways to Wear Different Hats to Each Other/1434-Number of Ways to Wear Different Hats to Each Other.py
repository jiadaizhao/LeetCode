import collections
from functools import lru_cache
class Solution:
    def numberWays(self, hats: List[List[int]]) -> int:
        hat2People = collections.defaultdict(list)
        for p, hat in enumerate(hats):
            for h in hat:
                hat2People[h].append(p)

        MOD = 10 ** 9 + 7
        n = len(hats)
        @lru_cache(None)
        def dfs(peopleMask, idHat):
            if peopleMask == (1 << n) - 1:
                return 1
            
            if idHat > 40:
                return 0

            result = dfs(peopleMask, idHat + 1)
            for p in hat2People[idHat]:
                if (peopleMask & (1 << p)):
                    continue
                result = (result + dfs(peopleMask | (1 << p), idHat + 1)) % MOD
             
            return result

        return dfs(0, 1)
