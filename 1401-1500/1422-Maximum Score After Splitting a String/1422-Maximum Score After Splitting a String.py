import math
class Solution:
    def maxScore(self, s: str) -> int:        
        count0 = count1 = 0
        maxDiff = -math.inf
        for i, c in enumerate(s):
            if c == '0':
                count0 += 1
            else:
                count1 += 1
            if i != len(s) - 1:
                maxDiff = max(maxDiff, count0 - count1)
        
        return maxDiff + count1
