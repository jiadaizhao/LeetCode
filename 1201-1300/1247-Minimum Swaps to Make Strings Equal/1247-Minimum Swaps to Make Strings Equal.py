class Solution:
    def minimumSwap(self, s1: str, s2: str) -> int:
        x1 = x2 = y1 = y2 = 0
        for c1, c2 in zip(s1, s2):
            if c1 != c2:
                if c1 == 'x':
                    x1 += 1
                else:
                    y1 += 1
                if c2 == 'x':
                    x2 += 1
                else:
                    y2 += 1
                    
        if (x1 + x2) & 1 or (y1 + y2) & 1:
            return -1
        return x1 // 2 + y1 // 2 + (x1 & 1) * 2
