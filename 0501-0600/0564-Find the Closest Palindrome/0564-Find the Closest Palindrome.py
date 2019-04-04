import math
class Solution:
    def nearestPalindromic(self, n: str) -> str:
        candidates = [10**len(n) + 1, 10**(len(n) - 1) - 1]
        prefix = int(n[:(len(n) + 1) // 2])
        for i in range(-1, 2):
            p = str(prefix + i)
            candidates.append(int(p + p[-1 - (len(n)&1): -len(p) - 1: -1]))
        
        minVal = num = int(n)
        minDiff = math.inf
        for c in candidates:
            if c != num:
                diff = abs(num - c)
                if diff < minDiff:
                    minDiff = diff
                    minVal = c
                elif diff == minDiff and c < minDiff:
                    minVal = c
        return str(minVal)
