class Solution:
    def numberOfSubstrings(self, s: str) -> int:
        total = 0
        ai = bi = ci = -1
        for i, c in enumerate(s):
            if c == 'a':
                ai = i
            elif c == 'b':
                bi = i
            else:
                ci = i
                
            total += min(ai, bi, ci) + 1
        return total
