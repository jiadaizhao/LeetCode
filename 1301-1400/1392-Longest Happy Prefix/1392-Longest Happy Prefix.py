class Solution:
    def longestPrefix(self, s: str) -> str:
        lps = [0] * len(s)
        l = 0
        i = 1
        while i < len(s):
            if s[i] == s[l]:
                lps[i] = l + 1
                i += 1
                l += 1
            elif l != 0:
                l = lps[l - 1]
            else:
                i += 1
        return s[0: lps[-1]]
