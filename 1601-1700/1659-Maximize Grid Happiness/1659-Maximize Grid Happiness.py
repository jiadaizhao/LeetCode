from functools import lru_cache
class Solution:
    def getMaxGridHappiness(self, m: int, n: int, introvertsCount: int, extrovertsCount: int) -> int:
        def calDiff(r, c, inMask, exMask, d):
            result = 0
            if r > 0:
                up = 1 << (n - 1)
                if inMask & up:
                    result += d - 30
                if exMask & up:
                    result += d + 20
            if c > 0:
                if inMask & 1:
                    result += d - 30
                if exMask & 1:
                    result += d + 20
            
            return result
        
        @lru_cache(None)
        def dfs(curr, inMask, exMask, inCount, exCount):
            if curr == m * n:
                return 0
            r, c = divmod(curr, n)
            nextInMask = (inMask << 1) & ((1 << n) - 1)
            nextExMask = (exMask << 1) & ((1 << n) - 1)
            result = dfs(curr + 1, nextInMask, nextExMask, inCount, exCount)
            if inCount > 0:
                happiness = 120 + calDiff(r, c, inMask, exMask, -30)
                result = max(result, happiness + dfs(curr + 1, nextInMask + 1, nextExMask, inCount - 1, exCount))
            if exCount > 0:
                happiness = 40 + calDiff(r, c, inMask, exMask, 20)
                result = max(result, happiness + dfs(curr + 1, nextInMask, nextExMask + 1, inCount, exCount - 1))
            return result
       
        return dfs(0, 0, 0, introvertsCount, extrovertsCount)
