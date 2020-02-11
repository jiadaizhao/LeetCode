class Solution:
    def minWindow(self, S: str, T: str) -> str:
        m, n = len(S), len(T)
        if m < n:
            return ''
        start = [-1] * (n + 1)
        start[0] = 0
        minLen, minStart = m + 1, -1
        for i in range(1, m + 1):
            for j in range(min(i, n), 0, -1):
                if S[i - 1] == T[j - 1]:
                    start[j] = start[j - 1]
            start[0] = i
            if start[n] != -1 and i - start[n] < minLen:
                minStart = start[n]
                minLen = i - start[n]
        
        return S[minStart: minStart + minLen] if minStart != -1 else ''
