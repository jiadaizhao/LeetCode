class Solution:
    def countSubstrings(self, s: str, t: str) -> int:
        m, n = len(s), len(t)
        same = [[0] * (n + 1) for _ in range(m + 1)]
        diff1 = [[0] * (n + 1) for _ in range(m + 1)]
        result = 0
        for i in range(1, m + 1):
            for j in range(1, n + 1):
                if s[i - 1] == t[j - 1]:
                    same[i][j] = 1 + same[i - 1][j - 1]
                    diff1[i][j] = diff1[i - 1][j - 1]
                else:
                    diff1[i][j] = 1 + same[i - 1][j - 1]
                result += diff1[i][j]
        return result
