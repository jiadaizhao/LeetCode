class Solution:
    def isOneEditDistance(self, s: str, t: str) -> bool:
        m, n = len(s), len(t)
        if m > n:
            m, n, s, t = n, m, t, s
        if n - m > 1:
            return False
        for i in range(m):
            if s[i] != t[i]:
                if m == n:
                    return s[i + 1:] == t[i + 1:]
                else:
                    return s[i:] == t[i+1:]
        return m + 1 == n
