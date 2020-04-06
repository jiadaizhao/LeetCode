from functools import lru_cache
class Solution:
    def findGoodStrings(self, n: int, s1: str, s2: str, evil: str) -> int:
        m = len(evil)
        lps = [0] * m
        i = 1
        l = 0
        while i < m:
            if evil[i] == evil[l]:
                lps[i] = l + 1
                i += 1
                l += 1
            elif l != 0:
                l = lps[l - 1]
            else:
                i += 1
        
        MOD = 10 ** 9 + 7
        @lru_cache(None)
        def dfs(start, pre1, pre2, preE):
            if preE == m:
                return 0
            if start == n:
                return 1
            
            total = 0
            first = ord(s1[start]) if pre1 else ord('a')
            last = ord(s2[start]) if pre2 else ord('z')
            
            for ci in range(first, last + 1):
                c = chr(ci)
                
                _pre1 = pre1 and ci == first
                _pre2 = pre2 and ci == last

                _preE = preE
                while _preE and c != evil[_preE]:
                    _preE = lps[_preE - 1]
                if c == evil[_preE]:
                    _preE += 1

                total += dfs(start + 1, _pre1, _pre2, _preE)
                total %= MOD
            
            return total
        
        return dfs(0, True, True, 0)
