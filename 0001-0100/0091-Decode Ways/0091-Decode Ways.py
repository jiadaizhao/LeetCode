class Solution:
    def numDecodings(self, s: str) -> int:
        if len(s) == 0:
            return 0
        dp0 = dp1 = 1
        for i in range(1, len(s) + 1):
            dp2 = 0
            if s[i - 1] != '0':
                dp2 += dp1
            if i >= 2 and (s[i - 2] == '1' or (s[i - 2] == '2' and '0' <= s[i - 1] <= '6')):
                dp2 += dp0
            dp0 = dp1
            dp1 = dp2
        return dp1
