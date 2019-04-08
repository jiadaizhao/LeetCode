class Solution:
    def countSubstrings(self, s: str) -> int:
        count = 0
        for center in range(len(s)*2 - 1):
            left = center // 2
            right = left + (center&1)
            while left >= 0 and right < len(s) and s[left] == s[right]:
                count += 1
                left -= 1
                right += 1
        return count

class Solution2:
    def countSubstrings(self, s: str) -> int:
        T = '#'.join('^{}$'.format(s))
        n = len(T)
        P = [0] * n
        C = R = 0
        for i in range(1, n - 1):
            if R > i:
                P[i] = min(R - i, P[2*C - i])
                
            while T[i + 1 + P[i]] == T[i - 1 - P[i]]:
                P[i] += 1
                
            if i + P[i] > R:
                C, R = i, i + P[i]
                
        return sum((l + 1) // 2 for l in P)
