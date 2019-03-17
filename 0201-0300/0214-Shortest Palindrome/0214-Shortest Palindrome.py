class Solution:
    def shortestPalindrome(self, s: str) -> str:
        temp = s + '#' + s[::-1]
        i = 1
        l = 0
        lps = [0] * len(temp)
        while i < len(temp):
            if temp[i] == temp[l]:
                lps[i] = l + 1
                i += 1
                l += 1
            elif l != 0:
                l = lps[l - 1]
            else:
                i += 1
        return s[l:][::-1] + s
