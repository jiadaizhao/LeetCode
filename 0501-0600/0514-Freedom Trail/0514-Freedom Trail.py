import math
import collections
class Solution:
    def findRotateSteps(self, ring: str, key: str) -> int:
        table = collections.defaultdict(list)
        for i, c in enumerate(ring):
            table[c].append(i)

        dp = [[math.inf]*len(ring) for _ in range(len(key))]
        for j in range(len(ring)):
            if key[0] == ring[j]:
                dp[0][j] = min(j, len(ring) - j) + 1
        
        for i in range(1, len(key)):
            for j in table[key[i]]:
                for k in table[key[i - 1]]:
                    dp[i][j] = min(dp[i][j], dp[i - 1][k] + min(abs(j - k), len(ring) - abs(j - k)) + 1)
                    
        result = math.inf
        for j in table[key[-1]]:
            result = min(result, dp[-1][j])
        return result
